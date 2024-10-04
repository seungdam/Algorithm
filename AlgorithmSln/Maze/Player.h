#pragma once

class CMap;







class CPlayer
{
	enum
	{
		UPDATE_TICK = 100
	};
	
	

private:
	POS pos;
	int32 dir = UP;
	CMap* maze = nullptr;
	vector<POS> myPath;
	int32 myPathIdx = 0;
	uint64 accumlateTick = 0.f;

public:
	CPlayer();
	~CPlayer();
	void Init(CMap* map);
	void SetPos(POS);
	POS GetPos();
	void Update(uint64 deltaTick);
	bool IsCanMove(const POS& pos);
	void RightHandNavigate();
	void BFSNavigate();
	void AStarNavigate();
};

// A* & 다익스트라

// A*는 시작점 기준으로 떨어진 거리와 목적지 기준으로 떨어진 거리를 모두 고려해서 점수를 매긴다.


