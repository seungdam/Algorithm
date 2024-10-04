#include "pch.h"


int elapsed_time{ 0 };

template<typename Ty>
class JobComapre
{
public:
	bool operator()(const Ty& item1, const Ty& item2)
	{

	}
};

int solution(vector<vector<int>> jobs)
{
	int answer;
	
	vector<int> accumulate_time;
	sort(jobs.begin(), jobs.end(),[](const auto& a, const auto& b)
	{
			if (a[0] == b[0])  return a[1] < b[1];
			return a[0] < b[0];
	}); 
	for (auto i : jobs)
	{

	}

}