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

	// edges 연결 확인

	bool connect = false;
	for (auto e : vertexes[0].edges)
	{
		if (e == &vertexes[3]) connect = true;
	}
}

void CreateGraphAdjacentList()
{
	vector<vector<int>> adjacent(6); // adjacent : 인접한

	// std::pair를 사용해 가중치도 포함시키기
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

// 간선과 간선이 빽빽한 경우와 느슨한 경우를 잘 생각해서 그래프를 구현하는 것이 중요
// EX 친구관계 네트워크 VS 지하철 노선도 ... ETC

void CreateGraphAdjacentMatrix()
{
	// edge를 따로 관리 (2차원 배열 활용)
	// idea: o,x 대신 가중치 넣기도 가능
	// V0 [X][0][X][0][X][X]
	// V1 [0][X][0][0][X][X]
	// V2 [X][X][X][X][X][X]
	// V3 [X][X][X][X][0][X]
	// V4 [X][X][X][X][X][X]
	// V5 [X][X][X][X][0][X]
	// adjacent[from][to] = ? 를 통해 연결여부 확인
	vector<vector<bool>> adjacent(6, vector<bool>(6, false)); // adjacent : 인접한

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
	// Idea: o,x 대신 가중치 넣기도 가능
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