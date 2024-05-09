#include "pch.h"
#include "MapRenderer.h"

CMapRenderer cmr(25);

int main()
{
    uint64 lastTick = 0;
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
