#include "pch.h"
#include "Player.h"
#include "Map.h"
#include <map>

inline int32 getHuristicValue(const POS& loc, const POS& dest)
{
	return 10 * (abs(dest.y - loc.y) + abs(dest.x - loc.x));
}

int32 moveCost[]
{
	10,10,10,10,
	14,14,14,14
};

struct PQNode
{
	int32 f; // f = g + h
	int32 g;
	POS p;
	bool operator<(const PQNode& rhs) const { return f < rhs.f; }
	//bool operator>(const PQNode& rhs) { return f > rhs.f; }
	bool operator==(const PQNode& rhs) const { return f == rhs.f; }
	bool operator>(const PQNode& rhs) const { return f > rhs.f; }
};

POS frontWeight[]
{
	POS{0, -1}, // up
	POS{1,  0}, // right
	POS{0,  1}, // down
	POS{-1, 0}, // left

	POS{1,-1},  // up right
	POS{-1,1},   // down right
	POS{1, 1},  // down left
	POS{-1,-1} // up left
};


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}


void CPlayer::Init(CMap* map)
{
	maze = map;
	SetPos(maze->GetEnterPos());
	//BFSNavigate();
	AStarNavigate();
}

void CPlayer::SetPos(POS p)
{
	pos = p;
}

POS CPlayer::GetPos()
{
	return pos;
}

void CPlayer::Update(uint64 deltaTick)
{
	if (myPathIdx >= myPath.size())
		return;

	accumlateTick += deltaTick;
	if (accumlateTick >= UPDATE_TICK)
	{
		accumlateTick = 0.f;
		pos = myPath[myPathIdx];
		++myPathIdx;
	}
}

bool CPlayer::IsCanMove(const POS& pos)
{
	TileType tt = maze->GetTileType(pos);
	return (tt == TileType::EMPTY);
}

void CPlayer::RightHandNavigate()
{
	POS tempPos = pos;
	POS dest = maze->GetExitPos();
	myPath.clear();
	myPath.push_back(tempPos);

	while (tempPos != dest)
	{
		// path finding Logic
		int32 rightDir = (dir + 1) % DIR_COUNT;
		int32 leftDir = (dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (IsCanMove(tempPos + frontWeight[rightDir]))// 1. 현재 방향 기준 오른쪽 이동 가능 여부 파악
		{
			dir = rightDir;  // 방향 전환
			tempPos += frontWeight[dir];
			myPath.push_back(tempPos);
		}
		else if (IsCanMove(tempPos + frontWeight[dir]))	// 2. 현재 방향 기준 전진 가능 여부 파악
		{
			tempPos += frontWeight[dir];
			myPath.push_back(tempPos);
		}
		else // 3. 왼쪽으로 방향 회전
		{
			dir = leftDir;
		}
	}

	stack<POS> impleRoute;
	for (auto iter = myPath.begin(); iter != (myPath.end() - 1); ++iter)
	{
		if (!impleRoute.empty() && impleRoute.top() == *(iter + 1))
		{
			impleRoute.pop();
		}
		else
		{
			impleRoute.push(*iter);
		}
	}
	if (!impleRoute.empty())
	{
		impleRoute.push(myPath.back());
	}
	myPath.clear();
	while (!impleRoute.empty())
	{
		myPath.push_back(impleRoute.top());
		impleRoute.pop();
	}

	std::reverse(myPath.begin(), myPath.end());
}

// 너비우선탐색
void CPlayer::BFSNavigate()
{
	POS from = pos;
	POS dest = maze->GetExitPos();	
	pos = maze->GetEnterPos();
	int32 size = maze->GetMapSize();

	std::array<bool, cMaxHeight> discovered[cMaxWidth];

	for (auto& i : discovered)
	{
		for (auto& k : i) k = false;
	}


	map<POS, POS> ppath;
	ppath[from] = from;
	discovered[from.y][from.x] = true;
	queue<POS> bfsq;
	bfsq.push(from);
	

	while (!bfsq.empty())
	{
		 from = bfsq.front();
		 bfsq.pop();
		if (from == dest)
		{
			myPath.clear();
			break;
		}
		for (auto dir : frontWeight)
		{
			POS to = from + dir;
			
 			if (!IsCanMove(to)) continue;
			if (discovered[to.y][to.x]) continue;
			
			bfsq.push(to);
			discovered[to.y][to.x] = true;
			
			ppath[to] = from;
		}
	}

	
	// ppath를 통해 기록한 위치를 추적
	
	while (true)
	{
		myPath.push_back(from);
		if (from == ppath[from])
		{
			break;
		}
		from = ppath[from];
	}

	reverse(myPath.begin(), myPath.end());
}



void CPlayer::AStarNavigate()
{
	// 거리 비용
	// F = G + H
	// G = 시작점에서 해당 지점까지 이동하는데 드는 비용
	// H = 목적지에서 얼마나 가까운지

	POS enter = maze->GetEnterPos();
	POS dest = maze->GetExitPos();
	const int32 size = maze->GetMapSize();
	
	vector<vector<bool>>  discovered(size, vector<bool>(size, false));
	vector<vector<int32>> totalCost(size, vector<int>(size, INT32_MAX)); // y,x로 이동하기 위한 토탈 코스트(G + H)를 담는 곳
	
	map<POS, POS> parent;
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq; // 예약 시스템을 구현하기 위한 자료구조로 우선순위 큐를 채택


	// 1. 발견 시스템 구현
	// 2. 최적 경로 갱신하는 예외처리 기능

	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - pos.y) + abs(dest.x - pos.x)); // 휴리스틱 공식
		pq.push(PQNode{ g + h,g, enter });
		totalCost[enter.y][enter.x] = g + h;
		parent[enter] = enter;
	}

	while (!pq.empty())
	{
		// 다음 경로 후보 찾기
		auto node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 탐색 
		// 이 과정에서 이미 최적의 경로를 찾은 경우 스킵
		
		if (discovered[node.p.y][node.p.x]) continue;		 // 이미 닫힌(발견된) 경로의 경우 
		if (totalCost[node.p.y][node.p.y] < node.f) continue; // 이미 베스트 케이스가 발견된 경우
			// 목적지 도달 시 종료
		discovered[node.p.y][node.p.x] = true;
		if (node.p == dest)
		{
			break;
		}
		for (int32 dir = 0; dir < DIR_COUNT; ++dir)
		{
			auto nextPos = node.p + frontWeight[dir];
			if (!IsCanMove(nextPos)) continue;
			if (discovered[nextPos.y][nextPos.x]) continue;
			auto nextG = node.g + moveCost[dir];
			auto nextH = getHuristicValue(nextPos, dest);
			if (totalCost[nextPos.y][nextPos.x] <= nextG + nextH) continue; // 최적의 경로가 아닌 경우 스킵

			totalCost[nextPos.y][nextPos.x] = nextG + nextH;
			pq.push(PQNode{ nextG + nextH, nextG, nextPos });
			parent[nextPos] = node.p;

		}
	}

	POS tmp = dest;
	myPath.clear();
	myPathIdx = 0;

	while (true)
	{
		myPath.push_back(tmp);
		if (tmp == parent[tmp])
		{
			break;
		}
		tmp = parent[tmp];
	}

	reverse(myPath.begin(), myPath.end());
}
