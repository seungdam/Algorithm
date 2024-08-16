#include "pch.h"
#include <random>


random_device rd;
default_random_engine dre(rd());
uniform_int_distribution<int> rgb(10, 231);

// Graph Sample
// 
//     �� �� 2
// 0 �� 1  
//     �� �� 3 �� 4 �� 5
int cnt1 = 0;
int cnt2 = 0;
// BFS ���� �켱 Ž��
struct Vertex
{
	int data;
};

vector<Vertex> vertices(6);
vector<vector<int>> adjacent(6); // adjacent : ������
vector<vector<bool>> adjacent_matrix(6, vector<bool>(6, false)); // adjacent : ������
vector<bool> visited(6, false); // �� ��ȯ Ž���� �����ϱ� ���� ��ȸ�� ���� üũ

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
	adjacent_matrix[1][1] = true;
	adjacent_matrix[1][2] = true;
	adjacent_matrix[1][3] = true;
	adjacent_matrix[3][4] = true;
	adjacent_matrix[5][4] = true;
}



void DFSList(int enter) // enter: ���� ���
{   
	
	visited[enter] = true;
	for (int i = 0; i < cnt1; ++i) cout << "       ";
	cout << format("\033[38;5;{}m [{}]\033[0m", rgb(dre), enter);
	for (auto i : adjacent[enter])
	{
		auto to = i;
		if (!visited[to]) // doesn't visited
		{
			cout << format(" -> [{}] \033[0m\n", to);
			++cnt1;
			DFSList(to);
		}

	}

	// 5���� Ž������ ���Ѵ�...
}

void DFSMatrix(int from) // enter: ���� ���
{
	
	visited[from] = true;
	for (int i = 0; i < cnt2; ++i) cout << "       ";
	cout << format("\033[38;5;{}m [{}]\033[0m", rgb(dre), from);
	
	for (int to = 0; to < 6; ++to)
	{
		if (!adjacent_matrix[from][to]) continue; // doesn't adjacent
		if (!visited[to])
		{
			cout << format(" -> [{}] \033[0m\n", to);
			++cnt2;
			DFSMatrix(to);
		}
	}

	// 5���� Ž������ ���Ѵ�...
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
	cout << "\n\033[1; 33m[Matrix]\n";
	DFSMatrix(0);

	cout << "\n[DFSAll()]\n";
	DFSAll();
}