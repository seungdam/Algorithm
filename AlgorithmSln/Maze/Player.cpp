#include "pch.h"
#include "Player.h"
#include "Map.h"


POS frontWeight[4]
{
	POS{0, -1}, // up
	POS{1,  0}, // right
	POS{0,  1}, // down
	POS{-1, 0} // left
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
	POS dest = maze->GetExitPos();
	POS tempPos = pos;
	myPath.clear();
	myPath.push_back(tempPos);



	while (tempPos != dest)
	{
		// path finding Logic
		int32 rightDir = (dir + 1) % DIR_COUNT;
		int32 leftDir =  (dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (IsCanMove(tempPos + frontWeight[rightDir]))// 1. ���� ���� ���� ������ �̵� ���� ���� �ľ�
		{
			dir = rightDir;  // ���� ��ȯ
			tempPos += frontWeight[dir];
			myPath.push_back(tempPos);
		}
		else if (IsCanMove(tempPos + frontWeight[dir]))	// 2. ���� ���� ���� ���� ���� ���� �ľ�
		{
			tempPos += frontWeight[dir];
			myPath.push_back(tempPos);
		}
		else // 3. �������� ���� ȸ��
		{
			dir = leftDir;
		}
	}

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
