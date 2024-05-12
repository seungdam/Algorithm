#pragma once

class CMap;

class CPlayer
{
private:
	POS pos;
	int32 dir = Dir::UP;
	CMap* maze = nullptr;
public:
	CPlayer();
	~CPlayer();
	void Init(CMap* map);
	void SetPos(POS);
	POS GetPos();
	void Update(uint64 deltaTick);

};

