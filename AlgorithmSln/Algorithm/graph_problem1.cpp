#include "pch.h"

int mysol(int n, vector<vector<int>> edge)
{
	int answer = 0;
	vector<bool> discovered(n, false);
	vector<int>  distance(n, 0);
	vector<vector<int>> nedge(n);

	for (auto i : edge)
	{
		nedge[i[0] - 1].push_back(i[1] - 1);
		nedge[i[1] - 1].push_back(i[0] - 1);
	}

	queue<int> bfsq;
	bfsq.push(0);
	int from = 0; // 1
	discovered[0] = true;

	while (!bfsq.empty())
	{
		from = bfsq.front();
		bfsq.pop();

		for (auto next : nedge[from])
		{
			if (discovered[next - 1]) continue;
			discovered[next - 1] = true;
			bfsq.push(next - 1);
			distance[next - 1] = distance[from] + 1;
		}
	}

	auto max_dist = *max_element(distance.begin(), distance.end());
	answer = count(distance.begin(), distance.end(), max_dist);
	return answer;
}