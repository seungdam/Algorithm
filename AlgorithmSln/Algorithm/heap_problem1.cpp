#include "pch.h"


int solution(vector<int> scoville, int K)
{
	int cnt{ 0 };
	priority_queue<int,vector<int>,greater<int>> pq;

	for (auto i : scoville)
	{
		pq.push(i);
	}
	
	while (pq.top() < K)
	{
		if (pq.size() == 1) return -1;
		auto lowest_scoville = pq.top(); pq.pop();
		auto second_lowerst_socville = pq.top(); pq.pop();
		auto new_scoville = lowest_scoville + (second_lowerst_socville * 2);
		pq.push(new_scoville);
		++cnt;
	}
	return cnt;

}

int main()
{
	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);
}