#include "pch.h"
#include <iomanip>
// Graph VS Tree : ����, ��带 ���� �����ϴ� �ڷ� �������� ���.

// Graph : ���� ������ �ƴ� ����� ����.
// Tree : ���� ������ ����.

// Tree ���
// Sibling : ���� �θ� ������ ���
// Leaf Node: �ָ��� ���
// Root Node: �ֻ��� ���
// ����(Depth) vs ����(Height)

// ���� 
// ��� Ư���� ��忡 �����ϱ� ���� ������ ����

// ����
// ���� ��� ������ ������Ʈ�� ���� max(depth)

// Tree <---> Recrusive
using NodePtr =  shared_ptr<struct TreeNode>;
struct TreeNode
{
	TreeNode() {};
	TreeNode(const string& str) : department(str) {};

	friend ostream& operator<<(ostream& os, const TreeNode& rhs)
	{
		os.fill('_');
		os << setw(12) << rhs.department;
		
		return os;
	}
	string department;
	vector<NodePtr> children;
};

NodePtr BuildTree()
{
	NodePtr root = make_shared<TreeNode>("���߽�");
	{
		NodePtr node = make_shared<TreeNode>(TreeNode{ "���α׷���" });
		root->children.push_back(node);
		NodePtr leaf = make_shared<TreeNode>(TreeNode{ "����" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "Ŭ��" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "����" });
		node->children.push_back(leaf);
	}
	{
		NodePtr node = make_shared<TreeNode>(TreeNode{ "������" });
		root->children.push_back(node);
		NodePtr leaf = make_shared<TreeNode>(TreeNode{ "����" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "����" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "���丮" });
		node->children.push_back(leaf);
	}
	{
		NodePtr node = make_shared<TreeNode>(TreeNode{ "��Ʈ" });
		root->children.push_back(node);
		NodePtr leaf = make_shared<TreeNode>(TreeNode{ "���" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "ĳ����" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "����" });
		node->children.push_back(leaf);
	}
	return root;
}

void PrintTree(NodePtr node, int depth)
{
	for (int i = 0; i < depth; ++i)
	{
		cout << "	";
	}
	if(depth != 0) cout << "��";
	cout << *node << "\n";
	for (auto& c : node->children)
	{
		PrintTree(c,depth + 1);
	}
}


int GetHeight(NodePtr root)
{
	int height{ 1 };
	for (auto& c : root->children)
	{
		height = max(height, GetHeight(c) + 1);
	}
	return height;
}
int main()
{
	auto root = BuildTree();
	PrintTree(root, 0);
	cout << GetHeight(root);
}