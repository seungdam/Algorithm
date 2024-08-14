#include <iostream>
#include <vector>
#include <list>
#include "Vector.h"

using namespace std;

int main()
{
	MyVector<int> v;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << "\n";
	}
	
	v.clear();
	for (int i = 0; i < 100; ++i)
	{
		cout << v[i] << "\n";
	}


}
