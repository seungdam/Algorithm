#include "pch.h"


int solution(vector<int> citations)
{

	int answer{ 0 };
	sort(citations.begin(), citations.end());
	
	for (int i = 0; i < citations.size(); ++i)
	{
		auto remain_report { (int)(citations.size() - i)}; // 나보다 큰 리포트 개수
		if (citations[i] <= remain_report)
		{
			return answer = i + 1;
		}
	}
	return citations.size() - 1;
}
int main()
{
	//idx  0 1 2 3 4
	//val  0 1 3 5 6
	// size = 5;
	// h = 0; val = 0; remain_report = 5; min 0 h_idx = 0
	// h = 1; val = 1; remain_report = 4; min 1 h_idx = 1
	// h = 2; val = 3; remain_report = 3; min 2 h_idx = 2
	

	cout << solution({ 0,1,3,5,6 }) << "\n";
	cout << solution({ 1,1,1,1,1,9,9,9 }) << "\n";
	cout << solution({ 2,10,11 }) << "\n";
}