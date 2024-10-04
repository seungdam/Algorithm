#include "pch.h"
#include <memory>
// 이진 탐색
// 정렬 상황을 가정했을 때, 효과적인 탐색방법


// 순차 탐색 --> O(N)
// 이진 탐색 --> O(logN)

// 문제점: 데이터의 삽입 삭제가 빈번한 경우 처리하기 어렵다.
// --> 이진 트리를 활용해야하는 이유
// --> 반면 데이터가 고정된 상태이고 배열로 관리하면 이진 탐색은 매우 우월한 방법



bool my_binary_search(const vector<int>& sorted_arr,const int& target)
{
	auto left{ 0 };
	auto right{ (int)sorted_arr.size() - 1 };

	while (left <= right)
	{
		auto mid = (int)((left + right) / 2);


		if (sorted_arr[mid] == target)
		{
			return true;
		}
		else if (sorted_arr[mid] > target)
		{
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return false;
}

template<typename Ty>
class BinarySearchTree
{
	struct Node
	{
		Ty data;
		Node* left{ nullptr };
		Node* right{ nullptr };
		Node* parent{ nullptr };
		std::shared_ptr<Node> get_shared_ptr() { return std::shared_from_this(); }
	};
	using NodePtr = shared_ptr<Node>;
public:
	void Insert(Ty key)
	{
		Node* new_node = new Node{ key };
		if (_root->get() == nullptr)
		{
			_root = make_shared<Node>(new_node);
			return;
		}

		NodePtr node = _root->get_shared_ptr();
	}
private:
	NodePtr _root{ nullptr };
};

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	cout << boolalpha << my_binary_search(v, 0);
}