#include "pch.h"
#include "Player.h"
#include "Map.h"

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
}
