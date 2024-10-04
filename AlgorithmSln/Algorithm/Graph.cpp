#include "pch.h"
#include "Graph.h"

void CreateSimpleGraph()
{

	struct Vertex1
	{

		int32 v;
		std::vector<int32> weights;
		std::vector<Vertex1*> edges;
	};

	std::vector<Vertex1> vertexes(6, Vertex1());
	vertexes[0].edges.push_back(&vertexes[1]);
	vertexes[0].weights.push_back(15);

	vertexes[0].edges.push_back(&vertexes[3]);
	vertexes[0].weights.push_back(35);

	vertexes[1].edges.push_back(&vertexes[0]);
	vertexes[1].weights.push_back(15);
	vertexes[1].edges.push_back(&vertexes[2]);
	vertexes[1].weights.push_back(5);
	vertexes[1].edges.push_back(&vertexes[3]);
	vertexes[1].weights.push_back(10);

	vertexes[3].edges.push_back(&vertexes[4]);
	vertexes[3].weights.push_back(5);

	vertexes[5].edges.push_back(&vertexes[4]);
	vertexes[5].weights.push_back(5);

	// edges ���� Ȯ��

	bool connect = false;
	for (auto e : vertexes[0].edges)
	{
		if (e == &vertexes[3]) connect = true;
	}
}

void CreateGraphAdjacentList()
{
	vector<vector<int>> adjacent(6); // adjacent : ������

	// std::pair�� ����� ����ġ�� ���Խ�Ű��
	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	bool connect = false;
	for (auto i : adjacent[0])
	{
		if (i == 3) connect = true;
	}
}

// ������ ������ ������ ���� ������ ��츦 �� �����ؼ� �׷����� �����ϴ� ���� �߿�
// EX ģ������ ��Ʈ��ũ VS ����ö �뼱�� ... ETC

void CreateGraphAdjacentMatrix()
{
	// edge�� ���� ���� (2���� �迭 Ȱ��)
	// idea: o,x ��� ����ġ �ֱ⵵ ����
	// V0 [X][0][X][0][X][X]
	// V1 [0][X][0][0][X][X]
	// V2 [X][X][X][X][X][X]
	// V3 [X][X][X][X][0][X]
	// V4 [X][X][X][X][X][X]
	// V5 [X][X][X][X][0][X]
	// adjacent[from][to] = ? �� ���� ���Ῡ�� Ȯ��
	vector<vector<bool>> adjacent(6, vector<bool>(6, false)); // adjacent : ������

	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][1] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	bool connect = adjacent[0][3];

}


void CreateWeightGraphAdjacentMatrix()
{
	// Idea: o,x ��� ����ġ �ֱ⵵ ����
	std::vector<vector<int>> adjacent =
	{
		std::vector<int> { -1, 15, -1, 35, -1, -1 },
		std::vector<int> { 15, -1,  1, 10, -1, -1 },
		std::vector<int> { -1, -1, -1, -1, -1, -1 },
		std::vector<int> { -1, -1, -1, -1,  5, -1 },
		std::vector<int> { -1, -1, -1, -1, -1, -1 },
		std::vector<int> { -1, -1, -1, -1,  5, -1 },
	};
}