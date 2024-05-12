#pragma once
#include "ConsoleHandler.h"

class CPlayer;

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL
};

class CMap
{
private:
	TileType maze_board[cMaxWidth][cMaxHeight]  = {};
	int32 maze_size = 0;
	CPlayer* p = nullptr;
public:
	CMap();
	~CMap();
	

	TileType GetTileType(POS pos);
	ConsoleColor GetTileColor(POS pos);
	POS GetEnterPos()
	{
		return { 1,1 };
	}
	POS GetExitPos()
	{
		return { maze_size - 2, maze_size - 2 };
	}

	void Init(const int32& size, CPlayer* player);
	void GenerateMap();
	void Render();
};

