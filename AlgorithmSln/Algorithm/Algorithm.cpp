#include "pch.h"
#include "MyList.h"
#include "MyVector.h"
int main()
{
	MyList<int32> ml;
	MyVector<char> str;

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2) ml.push_back(i);
		else ml.push_front(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		str.push_back(97 + i);
	}
	str.push_back('\0');

	for (const auto& i : ml)
	{
		cout << i << "\n";
	}

	for (const auto& c : str)
	{
		cout << c;
	}
	cout << "\n";
}
