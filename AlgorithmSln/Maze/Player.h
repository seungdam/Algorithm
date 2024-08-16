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
};

