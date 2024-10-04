#include "pch.h"

//  BFS의 단점
// 목적 없이 일단 전반적으로 모든 노드를 탐색하려는 성향을 가짐..
// 가중치 등의 요소를 활용하면, 좀 더 효율적으로 탐색할 수 있음.
// 그런 요소를 활용하는 것이 다익스트라. 


// BFS는 모든 간선간의 비용이 동일 --> 먼저 들어온 순서대로 방문을 수행
// 간선을 통해 노드를 지나갈 때마다, 가중치값을 더해줌으로써 최적노드를 탐색한다.

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

vector<int32> best(6, INT32_MAX); // 각 정점별 최적의 경로를
vector<int32> parent(6, -1);

// 비교연산 하기 위해 가장 큰 int값으로 초기화. inf
// 따로 목적지가 정해지지 않고 시작지점 기준 단거리의 노드를 계속해서 탐색한다.

void Dijikstra(int32 from)
{

	priority_queue<GraphNode, vector<GraphNode>,greater<GraphNode>> discovered;
	// 발견된 목록. 먼저 들어오면 먼저 탐색하는 Queue와 달리
	// 최적 루트에 따라 이동하는 경우기 때문에 List로 구현
	
	

	discovered.push(GraphNode{ from, 0 }); // 시작점은 거리가 0
	best[from] = 0; // 시작점 기준, 시작점까지 경로 코스트는 0
	parent[from] = from;

	while (!discovered.empty())
	{
		// bfs와 다른 점
		// 들어온 순서대로 탐색하는 것이 아닌 최적의 후보를 찾는다. 
		// 이동 cost가 가장 적은 것
		GraphNode best_item = discovered.top();

		// 발견된 노드 중, 가장 작은 경로 코스트가 두는 노드를 저장
		// 이때 우선순위 큐를 사용해 가장 적은 경로 순으로 탐색 수행
		

		int32 cost = best_item.cost;
		from = best_item.vertex;
		discovered.pop(); // pop

		if (best[from] < cost) // 이미 이전에 최적의 값을 찾아놓은 상태라면
		{
			cout << format("[now {} : cost {}] [best cost {}]\n", from, cost, best[from]);
			continue;
		}

		for (int32 to = 0; to < 6; ++to)
		{
			if (adjacent[from][to] == -1) continue; // 인접하지 않은 노드 거르기
			int32 next_cost = best[from] + adjacent[from][to]; // 새 경로의 가중치
			// 더 좋은 경로를 이미 찾았다면 스킵
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