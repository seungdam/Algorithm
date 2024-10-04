#include "pch.h"
#include <memory>
// ���� Ž��
// ���� ��Ȳ�� �������� ��, ȿ������ Ž�����


// ���� Ž�� --> O(N)
// ���� Ž�� --> O(logN)

// ������: �������� ���� ������ ����� ��� ó���ϱ� ��ƴ�.
// --> ���� Ʈ���� Ȱ���ؾ��ϴ� ����
// --> �ݸ� �����Ͱ� ������ �����̰� �迭�� �����ϸ� ���� Ž���� �ſ� ����� ���



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