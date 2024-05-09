#include "pch.h"
#include "MapRenderer.h"

const char* tile = "бс";

CMapRenderer::CMapRenderer()
{
    Init(0);
}

CMapRenderer::CMapRenderer(int32 size)
{
    Init(size);
    GenerateMap();
}

CMapRenderer::~CMapRenderer()
{
}

TileType CMapRenderer::GetTileType(POS pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= maze_size || pos.y >= maze_size) return TileType::NONE;

    return maze_board[pos.y][pos.x];
}

ConsoleColor CMapRenderer::GetTileColor(POS pos)
{
    TileType tt = GetTileType(pos);
    switch (tt)
    {
    case TileType::EMPTY:
        return ConsoleColor::GREEN;
    case TileType::NONE:
        return ConsoleColor::BLACK;
    case TileType::WALL:
        return ConsoleColor::RED;
    }
    return ConsoleColor::WHITE;
}

void CMapRenderer::Init(const int32& size)
{
    maze_size = size;
    GenerateMap();
}

void CMapRenderer::GenerateMap()
{
    for (int32 y = 0; y < maze_size; ++y)
    {
        for (int32 x = 0; x < maze_size; ++x)
        {
            if (x == 0 || y == 0 || x == (maze_size - 1) || y == (maze_size - 1))
            {
                maze_board[y][x] = TileType::WALL;
            }
            else
            {
                maze_board[y][x] = TileType::EMPTY;
            }
        }
    }
}

void CMapRenderer::Render()
{

    CConsoleHandler::SetCursorPos(0, 0);
    CConsoleHandler::SetCursorColor(ConsoleColor::RED);
    CConsoleHandler::ShowConsoleCursor(false);

    for (int32 w = 0; w < maze_size; ++w)
    {
        for (int32 h = 0; h < maze_size; ++h)
        {
            ConsoleColor curColor = GetTileColor(POS{ h,w });
            CConsoleHandler::SetCursorColor(curColor);
            cout << tile;
        }
        cout << "\n";
    }
}
