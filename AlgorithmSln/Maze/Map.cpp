#include "pch.h"
#include "Map.h"
#include "Player.h"



const char* tile = "бс";

CMap::CMap()
{
}

CMap::~CMap()
{
}

TileType CMap::GetTileType(POS pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= maze_size || pos.y >= maze_size)
    {
        return TileType::NONE;
    }

    return maze_board[pos.y][pos.x];
}

ConsoleColor CMap::GetTileColor(POS pos)
{

    if (pos == p->GetPos()) return ConsoleColor::YELLOW;
    if (pos == GetEnterPos() || pos == GetExitPos())
    {
        return ConsoleColor::BLUE;
    }

    TileType tt = GetTileType(pos);

    switch (tt)
    {
    case TileType::EMPTY:
        return ConsoleColor::GREEN;
    case TileType::WALL:
        return ConsoleColor::RED;
    }
    return ConsoleColor::WHITE;
}

void CMap::Init(const int32& size, CPlayer* player)
{
    maze_size = size;
    p = player;

    GenerateMap();
}

void CMap::GenerateMap()
{
    random_device rd;
    default_random_engine dre(rd());
    uniform_int_distribution<int32> uidDirection(0, 2);
    
   

    for (int32 y = 0; y < maze_size; ++y)
    {
        for (int32 x = 0; x < maze_size; ++x)
        {
            if (x == 0 || y == 0 || x == (maze_size - 1) || y == (maze_size - 1))
            {
                maze_board[y][x] = TileType::WALL;
            }
            else if (x % 2 == 0 || y % 2 == 0)
            {
                maze_board[y][x] = TileType::WALL;
            }
            else
            {
                maze_board[y][x] = TileType::EMPTY;
            }
        }
    }

   
    for (int32 y = 0; y < maze_size; ++y)
    {
        for (int32 x = 0; x < maze_size; ++x)
        {
            if (x % 2 == 0 || y % 2 == 0)
            {
                continue;
            }

            if (y == (maze_size - 2) && x == (maze_size - 2))
            {
                continue;
            }

            if (y == (maze_size - 2))
            {
                maze_board[y][x + 1] = TileType::EMPTY;
                continue;
            }

            if (x == (maze_size - 2))
            {
                maze_board[y + 1][x] = TileType::EMPTY;
                continue;
            }
            

            const int32 dir = uidDirection(dre);
            if (dir == 0)
            {
                maze_board[y][x + 1] = TileType::EMPTY;
            }
            else 
            {
                maze_board[y + 1][x] = TileType::EMPTY;
            }
        }
    }
}

void CMap::Render()
{

    CConsoleHandler::SetCursorPos(0, 0);
    CConsoleHandler::SetCursorColor(ConsoleColor::RED);
    CConsoleHandler::ShowConsoleCursor(false);
    
    for (int32 w = 0; w < maze_size; ++w)
    {
        for (int32 h = 0; h < maze_size; ++h)
        {
            ConsoleColor curColor = GetTileColor({ h,w });
           
            
            CConsoleHandler::SetCursorColor(curColor);
            cout << tile;
        }
        cout << "\n";
    }
}
