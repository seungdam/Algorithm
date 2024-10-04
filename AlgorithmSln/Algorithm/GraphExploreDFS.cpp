#include "pch.h"

random_device rd;
default_random_engine dre(rd());
uniform_int_distribution<int> rgb(105, 231);

// BFS 깊이 우선 탐색
struct Vertex
{
	int data;
};

vector<Vertex> vertices(6);
vector<vector<int>> adjacent(6); // adjacent : 인접한
vector<vector<bool>> adjacent_matrix(6, vector<bool>(6, false)); // adjacent : 인접한
vector<bool> visited(6, false); // 고리 순환 탐색을 방지하기 위해 순회한 노드는 체크

void CreateAdjacentList()
{
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };
}
void CreateAdjacentMatrix()
{
	
	adjacent_matrix[0][1] = true;
	adjacent_matrix[0][3] = true;
	adjacent_matrix[1][2] = true;
	adjacent_matrix[1][3] = true;
	adjacent_matrix[3][4] = true;
	adjacent_matrix[5][4] = true;
}

void DFSList(int, int);
void DFSList(int enter) // enter: 시작 노드
{   
	visited[enter] = true;
	cout << format("\033[38;5;{}m[{}]\033[0m", rgb(dre), enter);
	if (adjacent[enter].empty())
	{
		cout << " END\n";
	}
	for (auto i : adjacent[enter])
	{
		auto to = i;
		if (!visited[to]) // doesn't visited
		{
			cout << format(" -> [{}] \033[0m", to);
			DFSList(enter, to); // call recrusively
		}
	}
}
void DFSList(int parents, int currents)
{
	visited[currents] = true;
	cout << format("\033[38;5;{}m[{}] -> \033[38;5;{}m[{}] \033[0m", rgb(dre), parents, rgb(dre), currents);
	if (adjacent[currents].empty())
	{
		cout << " END\n";
	}
	for (auto i : adjacent[currents])
	{
		auto to = i;
		if (!visited[to]) // doesn't visited
		{
			DFSList(currents, to); // call recrusively
		}
	}
}

void DFSMatrix(int, int);
void DFSMatrix(int from) // enter: 시작 노드
{
	visited[from] = true;
	cout << format("\033[38;5;{}m[{}]", rgb(dre), from);
	for (int to = 0; to < 6; ++to)
	{
		if (!adjacent_matrix[from][to] || from == to) continue; // doesn't adjacent
		if (!visited[to])
		{
			DFSMatrix(from, to);
		}
	}
}
void DFSMatrix(int parent, int current) // enter: 시작 노드
{
	visited[current] = true;
	cout << format(" -> \033[38;5;{}m[{}] \033[0m", rgb(dre), current);
	
	int cnt{ 0 };
	for (int to = 0; to < 6; ++to)
	{
		if (!adjacent_matrix[current][to])
		{
			++cnt;
			continue; // doesn't adjacent
		}
		if (!visited[to])
		{
			DFSMatrix(current, to);
		}
	}
	if (cnt == 6) cout << "END\n";
}

void DFSAll()
{
	for (int i = 0; i < 6; ++i)
	{
		if (!visited[i]) DFSList(i);
	}
}

int main()
{
	CreateAdjacentList();
	CreateAdjacentMatrix();
	cout << "\033[1;33m[List]\n";
	DFSList(0);

	cout << "\n[DFSAll()]\n";
	DFSAll();

	for (int i = 0; i < 6; ++i) visited[i] = false;
	cout << "\n\n\033[1; 33m[Matrix]\n";
	DFSMatrix(0);

	cout << "\n[DFSAll()]\n";
	DFSAll();
}