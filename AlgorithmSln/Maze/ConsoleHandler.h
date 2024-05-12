#pragma once

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	BLUE = FOREGROUND_BLUE,
	GREEN = FOREGROUND_GREEN,
	YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN
};

class CConsoleHandler
{
public:
	static void SetCursorPos(int32 cx, int32 cy);
	static void SetCursorColor(ConsoleColor color);
	static void ShowConsoleCursor(bool flag);
};



