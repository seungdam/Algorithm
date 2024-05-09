#include "pch.h"
#include "ConsoleHandler.h"

void CConsoleHandler::SetCursorPos(int32 cx, int32 cy)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos = { static_cast<SHORT>(cx), static_cast<SHORT>(cy) };
	::SetConsoleCursorPosition(output, cursorPos);
}

void CConsoleHandler::SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<int16>(color));
}

void CConsoleHandler::ShowConsoleCursor(bool flag)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = flag;
	::SetConsoleCursorInfo(output, &cursorInfo);
}
