#pragma once
#include "ConsoleHandler.h"

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL,
};



class CMapRenderer
{
private:
	TileType maze_board[cMaxWidth][cMaxHeight]  = {};
	int32 maze_size = 0;
public:
	CMapRenderer();
	~CMapRenderer();
	CMapRenderer(int32);

	TileType GetTileType(POS pos);
	ConsoleColor GetTileColor(POS pos);

	void Init(const int32& size);
	void GenerateMap();
	void Render();
};

