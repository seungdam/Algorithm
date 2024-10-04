#include "pch.h"
#include <unordered_map>
random_device rd;
default_random_engine dre(rd());
uniform_int_distribution<int> rgb(105, 231);

//*** BFS(�ʺ� �켱 Ž��): ��ã�� �˰��� ������.
// Queue �ڷᱸ���� Ȱ���� ���� �ý����� �����ϴ� ���� key point
struct Vertex
{
	int32 v;
};

vector<Vertex> vertices(6);
vector<vector<int>> adjacent(6); // adjacent : ������
vector<bool> discovered(6, false); // �߰� ���� != �湮 ����

void CreateAdjacentList()
{
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };
}

void BFS(int32 enter)
{
	queue<int32> bfsq;
	vector<int32> distance(6, -1);

	bfsq.push(enter);
	distance[enter] = 0;
	discovered[enter] = true; 
	
	// work_flow
	// bfsq: f[0]b		discover: [o][x][x][x][x][x]
	// bfsq: f[]b		discover: [o][x][x][x][x][x]
	// bfsq: f[1][3]b   discover: [o][o][x][o][x][x]
	// bfsq: f[3]b		discover: [o][o][x][o][x][x]
	// bfsq: f[3][2]b	discover: [o][o][o][o][x][x]
	// bfsq: f[2]b		discover: [o][o][o][o][o][x]
	// bfsq: f[]b		discover: [o][o][o][o][o][x]

	cout << "\033[1;33m[BFS]\n";
	cout << format("\033[1;33mStart From [{}]\n\n", enter);
	int32 from = enter;

	while (!bfsq.empty())
	{
		from = bfsq.front();
		cout << format("\033[1;33mVisited \033[38;5;{}m[{}]\033[1;33m Distance From Enter [{}]\n", rgb(dre), from, distance[from]);
		bfsq.pop();
		cout << "\033[1;33m	  Discovered ";
		for (const auto& next : adjacent[from]) // ���� ��ġ�� ������ ��� �� Ž��
		{
			if (discovered[next]) continue; // �̹� �߰ߵ� ���� Ž������ X
			bfsq.push(next);
			discovered[next] = true;
			cout << format("[{}]",next);
			distance[next] = (distance[from] + 1);
		}
		cout << "\n\n";
	}
	cout << "\033[0m";
}

void BFSAll()
{
	for (int32 i = 0; i < discovered.size(); ++i)
	{
		if (!discovered[i]) BFS(i);
	}
}

int32 main()
{
	CreateAdjacentList();
	BFS(0);
	
	cout << "\n\n";
	BFSAll();
}