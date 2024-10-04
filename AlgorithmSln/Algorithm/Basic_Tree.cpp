#include "pch.h"
#include <iomanip>
// Graph VS Tree : 간선, 노드를 통해 관리하는 자료 구조임은 비슷.

// Graph : 계층 구조가 아닌 평등한 구조.
// Tree : 계층 구조를 가짐.

// Tree 용어
// Sibling : 같은 부모를 가지는 노드
// Leaf Node: 최말단 노드
// Root Node: 최상위 노드
// 깊이(Depth) vs 높이(Height)

// 깊이 
// 어떠한 특정한 노드에 도달하기 위한 간선의 개수

// 높이
// 가장 깊게 존재한 리프노트의 깊이 max(depth)

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
	NodePtr root = make_shared<TreeNode>("개발실");
	{
		NodePtr node = make_shared<TreeNode>(TreeNode{ "프로그래밍" });
		root->children.push_back(node);
		NodePtr leaf = make_shared<TreeNode>(TreeNode{ "서버" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "클라" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "엔진" });
		node->children.push_back(leaf);
	}
	{
		NodePtr node = make_shared<TreeNode>(TreeNode{ "디자인" });
		root->children.push_back(node);
		NodePtr leaf = make_shared<TreeNode>(TreeNode{ "전투" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "경제" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "스토리" });
		node->children.push_back(leaf);
	}
	{
		NodePtr node = make_shared<TreeNode>(TreeNode{ "아트" });
		root->children.push_back(node);
		NodePtr leaf = make_shared<TreeNode>(TreeNode{ "배경" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "캐릭터" });
		node->children.push_back(leaf);
		leaf = make_shared<TreeNode>(TreeNode{ "몬스터" });
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
	if(depth != 0) cout << "ㄴ";
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