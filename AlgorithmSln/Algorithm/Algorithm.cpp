#include "pch.h"
#include <format>
#include "MyList.h"
#include "MyVector.h"
#include "MyStack.h"

int main()
{
	cout << "===[List]===\n\n";
	MyList<int32> ml;
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2) ml.push_back(i);
		else ml.push_front(i);
	}
	cout << "[Head]";
	for (auto& i : ml)
	{
		cout << std::format("<->[{}]", *i);
	}
	cout << "<->[Tail]\n";
	cout << "After Erase: " << *(ml.begin() + 3) << "\n";
	ml.erase((ml.begin() + 3));
	cout << "[Head]";
	for (auto& i : ml)
	{
		cout << std::format("<->[{}]", *i);
	}
	cout << "<->[Tail]\n";

	cout << "\n===[Vector]===\n\n";
	MyVector<int8> str;
	for (int i = 0; i < 10; ++i)
	{
		str.push_back(97 + i);
	}
	str.push_back('\0');
	
	for (const auto& c : str)
	{
		cout << format("[{}]",c);
	}
	cout << "\n";

	cout << "\n===[Stack]===\n\n";
	MyStack<int32> ms;
	
	cout << " [in]: ";
	for (int32 i = 0; i < 10; ++i)
	{
		ms.push_back(i);
		if(i != 9) cout << std::format("[{}]->",i);
		else cout << std::format("[{}]", i);
	}
	cout << "\n";
	cout << "[out]: ";
	while (!ms.empty())
	{
		auto elm = ms.top();
		ms.pop();
		if (!ms.empty()) cout << std::format("[{}]->", elm);
		else cout << std::format("[{}]", elm);
	}

	
}
