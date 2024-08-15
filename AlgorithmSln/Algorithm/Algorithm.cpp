#include "pch.h"
#include <format>
#include "MyList.h"
#include "MyVector.h"
#include "MyStack.h"
#include "MyQueue.h"

int main()
{
	std::cout << "===[List]=== Dummy Node\n\n";
	MyList<int32> ml;
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2) ml.push_back(i);
		else ml.push_front(i);
	}
	std::cout << "[Head]";
	for (auto& i : ml)
	{
		cout << std::format("<->[{}]", *i);
	}
	std::cout << "<->[Tail]\n";
	std::cout << "\nAfter Erase: " << *(ml.begin() + 3) << "\n";
	ml.erase((ml.begin() + 3));
	std::cout << "[Head]";
	for (auto& i : ml)
	{
		cout << std::format("<->[{}]", *i);
	}
	std::cout << "<->[Tail]\n";
	
	std::cout << "\n===[Vector]=== Random Access\n\n";
	MyVector<int8> str;
	for (int i = 0; i < 10; ++i)
	{
		str.push_back(97 + i);
	}
	str.push_back('\0');
	
	for (const auto& c : str)
	{
		std::cout << format("[{}]",c);
	}
	std::cout << "\n";

	std::cout << "\n===[Stack]=== LIFO\n\n";
	
	MyStack<int32> ms;
	std::cout << " [in]: ";
	for (int32 i = 0; i < 10; ++i)
	{
		ms.push_back(i);
		if(i != 9) cout << std::format("[{}]->",i);
		else cout << std::format("[{}]", i);
	}
	std::cout << "\n";
	std::cout << "[out]: ";
	while (!ms.empty())
	{
		auto elm = ms.top();
		ms.pop();
		if (!ms.empty())
		{
			std::cout << std::format("[{}]->", elm);
		}
		else
		{
			cout << std::format("[{}]", elm);
		}
	}
	std::cout << "\n";

	std::cout << "\n===[Queue]=== FIFO\n\n";
	MyQueue<int32, deque> mq;

	std::cout << "\n     [front]					  [back]\n";
	std::cout << " [in]: ";
	for (int32 i = 0; i < 10; ++i)
	{
		mq.push(i);
		if (i != 9) cout << std::format("[{}]->", i);
		else cout << std::format("[{}]", mq.back());
	}
	
	std::cout << "\n[out]: ";
	while (!mq.empty())
	{
		auto elm = mq.front();
		mq.pop();
		if (!mq.empty())
		{
			std::cout << std::format("[{}]->", elm);
		}
		else
		{
			cout << std::format("[{}]", elm);
		}
	}
}
