#pragma once

#include "type.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <queue>
#include <random>
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
		return !(*this == other);
	}
	bool operator<(const POS& other) const
	{
		if (y != other.y) return y < other.y;
		 return x < other.x;
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

enum Dir
{
	UP = 0,
	RIGHT,
	DOWN,
	LEFT,
	DIR_COUNT
};

