#include "pch.h"
#include "Map.h"
#include "Player.h"


int main()
{
    uint64 lastTick = 0;
    CMap cmr;
    CPlayer p;
 
    cmr.Init(25, &p);
    p.Init(&cmr);

    cmr.GenerateMap();

    while (true)
    {
#pragma region handle Frame
        const uint64 curTick = ::GetTickCount64();
        const uint64 deltaTick = curTick - lastTick;
        lastTick = curTick;
#pragma endregion

        // Input
        // Logic 
        // 
        // Rendering
        cmr.Render();
        
        
        
    }
}
