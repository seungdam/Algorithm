#include "pch.h"
#include <typeinfo>
int arr[]{ 1,2,100,12,301,33,55,102,1 };
int arr2[]{ 1,2,100,12,301,33,55,102,1 };
int arr3[]{ 1,2,100,12,301,33,55,102,1 };
int arr4[]{ 1,2,100,12,301,33,55,102,1 };
int arr5[]{ 1,2,100,12,301,33,55,102,1 };
void myswap(int[], int, int);
void selection_sort(int size)
{
	if (size == 0) return;
	auto max{ 0 };
	auto m_idx{ 0 };
	for (auto i{ 0 }; i < size; ++i)
	{
		if (max < arr[i])
		{
			m_idx = i;
			max = arr[i];
		}
	}
	// t(n) = t(n - 1) + n + c(=> swap overhead)
	// t(n) = t(n - 2) + (n - 1) + n + c
	// t(n) = t(1) + n - (n - 2) + .... n + c
	// t(n) = n(n + 1) / 2 + c;
	// t(n) = O(n^2)
	myswap(arr, m_idx, size - 1);
	selection_sort(size - 1);
}
void myswap(int arr[], int from, int last)
{
	auto tmp = arr[from];
	arr[from] = arr[last];
	arr[last] = tmp;
}

void bubble_sort(int size)
{
	auto b_is_sorted = true;
	for (int j = size; j > 0; --j)
	{
		b_is_sorted = true;
		for (int i = 0; i < j - 1; ++i)
		{
			if (arr2[i] > arr2[i + 1])
			{
				myswap(arr2, i, i + 1);
				b_is_sorted = false;
			}
		}
		if (b_is_sorted) return;
	}
	// T(n) = ( n - 1 + n - 2 + n - 3 .... + 1);
}

void insert_sort(int size)
{
	// worst case
	// t(n) = 1 + 2 + ... n;
	// t(n) = n(n + 1) / 2
	// t(n) = O(N^2)
	for (int narr_size = 1; narr_size < size; ++narr_size)
	{
		int citer = narr_size - 1;
		auto next_item = arr3[citer + 1];
		// 정렬된 배열에 추가할 새로운 Item 결정

		// 기존 정렬된 배열에서 자리 탐색
		// 최고의 경우 O(1)
		// 최악의 경우 정렬된 배열의 개수만큼 탐색하게 됨 O(N)
		
		while (citer >= 1 && next_item < arr3[citer]) 
		{
			arr3[citer + 1] = arr3[citer];
			--citer;
		}
		arr3[citer + 1] = next_item;
	}
}


void merge( int beg, int pivot, int end)
{
	auto p{ beg }; // 0 
	auto q{ pivot + 1 }; // 2
	auto t{ 0 };


	vector<int> tmp(end - beg  + 1, 0);

	for (int i = beg; i <= q - 1; ++i) cout << "\033[1;31m[" << arr4[i] << "]";
	cout << "  ";
	for (int i = q; i <= end; ++i) cout << "\033[1;34m[" << arr4[i] << "]";
	std::cout << "\n\n\033[0mSORTING: ";
	while (p <= pivot && q  <= end)
	{
		if (arr4[p] <= arr4[q])
		{
			tmp[t++] = arr4[p++];
			cout << "\033[1;31m[" << tmp[t - 1] << "]";
		}
		else
		{
			tmp[t++] = arr4[q++];
			cout << "\033[1;34m[" << tmp[t - 1] << "]";
		}
	}
	while (p <= pivot)
	{
		tmp[t++] = arr4[p++];
		cout << "\033[1;31m[" << tmp[t - 1] << "]";
	}
	while (q <= end)
	{
		tmp[t++] = arr4[q++];
		cout << "\033[1;34m[" << tmp[t - 1] << "]";
	}
	cout << "\033[0m\n";
	t = 0;
	std::cout << format("MERGE [{}]~[{}] + [{}]~[{}] Result: ", beg ,pivot,pivot + 1, end);
	for (auto i : tmp) cout << "[" << i << "]";
	cout << "\n\n";
	for (int i = beg; i <= end; ++i)
	{
		arr4[i] = tmp[t++];
	}
	
}

void merge_sort(int beg , int end)
{

	if (beg < end) // 분해 가능할 때까지만 분해
	{
		auto q = (int)((beg + end) / 2); // 절반으로 나눈다.
		merge_sort(beg , q);
		merge_sort(q + 1, end);
		merge(beg, q, end);
	}
}


template<typename Ty, typename Predicate = less<Ty>>
void heapify_down(Ty* arr, int cidx, int size)
{
	auto parent { cidx };
	auto left{  2 * parent + 1 };
	auto right{ 2 * parent + 2 };
	auto next{ parent };
	auto pred = Predicate{};
	if (left < size)
	{
		// 5 < 3
		if (pred(arr[cidx], arr[left]))
		{
			next = left;
			myswap(arr, cidx, next);
		}
	}
	if (right < size)
	{
		// 5 < 2
		if (pred(arr[cidx], arr[right]))
		{
			next = right;
			myswap(arr, cidx, next);
		}
	}
	if (next == parent) return; // 이미 정렬됐으면 끝
	
	heapify_down(arr, next, size);
}

template<typename Ty, typename Predicate = less<Ty>>
void heapify_up(Ty* arr, int cidx)
{
	auto pred = Predicate{};
	auto parent{ (cidx - 1) / 2 };
	auto left { parent + 1 };
	auto right{ parent + 2 };
	if (parent < 0) return;

	if (pred(arr[parent], arr[left]))
	{
		myswap(arr, parent, left);
	}
	if (pred(arr[parent], arr[right]))
	{
		myswap(arr, parent, right);
	}
}

template<typename Ty, typename Predicate = less<Ty>>
void heap_sort(Ty* arr, int size)
{
	// build_heap
	for (int i = (size / 2) - 1; i >= 0; --i)
	{
		heapify_down<Ty, Predicate>(arr, i, size);
	}

	for (auto i = size - 1; i >= 0; --i)
	{
		myswap(arr, 0, i);
		heapify_down<Ty, Predicate>(arr, 0, i);
	}
}

int main()
{
	
	selection_sort(9);
	bubble_sort(9);
	insert_sort(9);

	std::cout << "\n===Selection Sort===\nComplexity: best == worst O(N^2)\n\n";
	for (auto i : arr)std::cout << i << " ";
	std::cout << "\n\n===Bubble Sort===\nComplexity: best O(N) | worst O(N^2)\n\n";
	for (auto i : arr2)std::cout << i << " ";
	std::cout << "\n\n===Insert Sort===\nComplexity: best O(N) | worst O(N^2)\n\n";
	for (auto i : arr3)std::cout << i << " ";

	std::cout << "\n\n===Merge Sort===\nComplexity: best == worst O(NlogN)\n\n";
	merge_sort(0, 8);

	
	std::cout << "\n\n===Heap Sort===\nComplexity: best == worst O(NlogN)\n\n";
	heap_sort<int>(arr5, 9);

	for (auto i : arr5) cout << i << " ";
}