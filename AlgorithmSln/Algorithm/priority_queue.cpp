#include "pch.h"
#include <random>

random_device rd;
default_random_engine dre(rd());
uniform_int_distribution<int> uid(10, 99);

// Heap Tree -> ���� Ʈ���� �� ����
// 1. ���� ��尪 >= ���� ��尪 (�ִ� �� ����) (�ּ� ���� �� �ݴ�)
// 2. ���� ���� Ʈ������ �Ѵ�.
// 3. ������ ���� �ݵ�� ���ʺ��� ä�����Ѵ�.

template<typename Ty, class Container = vector<Ty>, typename Predicate = less<Ty>>
class MyPriority_Queue
{
	Container _heap{};
	Predicate _pred{};
	int _size{ 0 };
public:
	void push(Ty val)
	{
		// �� ������ ������ �°� �ϴ� �߰�
		_heap.push_back(val);

		// �� ������ ����
		{
 			auto loc{ _heap.size() - 1};
			if(!loc) cout << format("Root: [{:^4}]\n", _heap[loc]);
			while (loc > 0) // root ��忡 ������ ������ �� ��ġ ����
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
	// �� ������ Ȱ���� ������ ������ ����
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