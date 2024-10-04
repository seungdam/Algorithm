#include "pch.h"

//  BFS�� ����
// ���� ���� �ϴ� ���������� ��� ��带 Ž���Ϸ��� ������ ����..
// ����ġ ���� ��Ҹ� Ȱ���ϸ�, �� �� ȿ�������� Ž���� �� ����.
// �׷� ��Ҹ� Ȱ���ϴ� ���� ���ͽ�Ʈ��. 


// BFS�� ��� �������� ����� ���� --> ���� ���� ������� �湮�� ����
// ������ ���� ��带 ������ ������, ����ġ���� ���������ν� ������带 Ž���Ѵ�.

struct Vertex
{
	int32 v;
};

struct GraphNode
{
	int32 vertex;
	int32 cost;

	bool operator<(const GraphNode& rhs) const { return cost < rhs.cost; }
	bool operator>(const GraphNode& rhs) const { return cost > rhs.cost; }
};

vector<Vertex> vs;
vector<vector<int>> adjacent;

void CreateGraph()
{
	vs.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	
	// filled matrix elm as weight
	// from - to = weight
	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[5][4] = 5;
}

vector<int32> best(6, INT32_MAX); // �� ������ ������ ��θ�
vector<int32> parent(6, -1);

// �񱳿��� �ϱ� ���� ���� ū int������ �ʱ�ȭ. inf
// ���� �������� �������� �ʰ� �������� ���� �ܰŸ��� ��带 ����ؼ� Ž���Ѵ�.

void Dijikstra(int32 from)
{

	priority_queue<GraphNode, vector<GraphNode>,greater<GraphNode>> discovered;
	// �߰ߵ� ���. ���� ������ ���� Ž���ϴ� Queue�� �޸�
	// ���� ��Ʈ�� ���� �̵��ϴ� ���� ������ List�� ����
	
	

	discovered.push(GraphNode{ from, 0 }); // �������� �Ÿ��� 0
	best[from] = 0; // ������ ����, ���������� ��� �ڽ�Ʈ�� 0
	parent[from] = from;

	while (!discovered.empty())
	{
		// bfs�� �ٸ� ��
		// ���� ������� Ž���ϴ� ���� �ƴ� ������ �ĺ��� ã�´�. 
		// �̵� cost�� ���� ���� ��
		GraphNode best_item = discovered.top();

		// �߰ߵ� ��� ��, ���� ���� ��� �ڽ�Ʈ�� �δ� ��带 ����
		// �̶� �켱���� ť�� ����� ���� ���� ��� ������ Ž�� ����
		

		int32 cost = best_item.cost;
		from = best_item.vertex;
		discovered.pop(); // pop

		if (best[from] < cost) // �̹� ������ ������ ���� ã�Ƴ��� ���¶��
		{
			cout << format("[now {} : cost {}] [best cost {}]\n", from, cost, best[from]);
			continue;
		}

		for (int32 to = 0; to < 6; ++to)
		{
			if (adjacent[from][to] == -1) continue; // �������� ���� ��� �Ÿ���
			int32 next_cost = best[from] + adjacent[from][to]; // �� ����� ����ġ
			// �� ���� ��θ� �̹� ã�Ҵٸ� ��ŵ
			if (next_cost >= best[to]) continue;

			discovered.push(GraphNode{ to, next_cost });
			best[to] = next_cost;
			parent[to] = from;
		}
	}
}

int32 main()
{
	CreateGraph();
	Dijikstra(0);

	for (int i = 0; i < 6; ++i)
	{
		cout << "[" << i << "]: " << best[i] << "\n";
	}
}