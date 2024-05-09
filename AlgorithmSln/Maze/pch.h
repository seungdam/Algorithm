#pragma once

#include "type.h"
#include <iostream>
#include <vector>
#include <windows.h>


using namespace std;


const int32 cMaxWidth = 100;
const int32 cMaxHeight = 100;

struct POS
{
	int32 x = 0;
	int32 y = 0;

	bool operator==(const POS& other)
	{
		return (x == other.x) && (y == other.y);
	}

	bool operator!=(const POS& other)
	{
		return (x != other.x) || (y != other.y);
	}

	POS operator+(const POS& other)
	{
		POS retVal;
		retVal.x = x + other.x;
		retVal.y = y + other.y;
		return retVal;
	}

	POS operator-(const POS& other)
	{
		POS retVal;
		retVal.x = x - other.x;
		retVal.y = y - other.y;
		return retVal;
	}

	POS& operator+=(const POS& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	POS& operator-=(const POS& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	POS& operator=(POS other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}
};

enum class Dir
{
	UP = 0,
	LEFT,
	DOWN,
	RIGHT
};

