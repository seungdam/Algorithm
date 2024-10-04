#include "pch.h"
#include <random>

random_device rd;
default_random_engine dre(rd());
uniform_int_distribution<int> uid(10, 99);

// Heap Tree -> 이진 트리의 한 종류
// 1. 상위 노드값 >= 하위 노드값 (최대 힙 기준) (최소 힙은 그 반대)
// 2. 완전 이진 트리여야 한다.
// 3. 최하위 노드는 반드시 왼쪽부터 채워야한다.

template<typename Ty, class Container = vector<Ty>, typename Predicate = less<Ty>>
class MyPriority_Queue
{
	Container _heap{};
	Predicate _pred{};
	int _size{ 0 };
public:
	void push(Ty val)
	{
		// 힙 공간의 구조에 맞게 일단 추가
		_heap.push_back(val);

		// 힙 재정렬 시작
		{
 			auto loc{ _heap.size() - 1};
			if(!loc) cout << format("Root: [{:^4}]\n", _heap[loc]);
			while (loc > 0) // root 노드에 도달할 때까지 재 배치 수행
			{
				auto parent{ 0 };
				if (1 == loc % 2)
				{
					// parent = k;
					// left = 2k + 1 right = 2k + 2
					parent = (loc - 1) / 2;
					
				}
				else parent = (loc / 2) - 1;
				cout << format("[{:^4}] Parent: [{:^4}]\n", _heap[loc], _heap[parent]);

				if (_pred(_heap[loc] , _heap[parent])) break;
				
				mswap(loc, parent);
				loc = parent;
			}
		}
	}
	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();
		auto loc{ 0 };
		while (true)
		{
			auto left = 2 * loc + 1;
			auto right = 2 * loc + 2;

			if (left >= _heap.size() || right >= _heap.size()) break;
			auto next{ loc };
			if (_pred(_heap[next] , _heap[left]))
			{
				next = left;
			}
			if (_pred(_heap[next] , _heap[right]))
			{
				next = right;
			}

			if (next == loc) break;
			mswap(loc, next);
			loc = next;
		}
	}
	bool empty() { return _heap.empty(); }
	void mswap(const int& idx1, const int& idx2)
	{
		Ty tmp = _heap[idx1];
		_heap[idx1] = _heap[idx2];
		_heap[idx2] = tmp;
	}
	Ty& top()
	{
		return _heap[0];
	}

	size_t size()
	{
		return _size;
	}
};

int main()
{
	// 힙 구조를 활용해 빠르게 정렬을 수행
	priority_queue<int, vector<int>, greater<int>> pq;
	
	MyPriority_Queue<int> mpq;

	for (int i = 0; i < 7; ++i)
	{
		auto elm = uid(dre);
		cout << "Push: " << elm << "\n";
		mpq.push(elm);
		
	}

	int cnt{ 1 };
	while(!mpq.empty())
	{
		cout << "POP:" << mpq.top() << "\n";
		++cnt;
		mpq.pop();
	}
}