#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	vector<vector<string>> tickets
	{
		{"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"}
	};

	map<string, vector<string>> m;

	for (auto i : tickets)
	{
		m[i[0]].push_back(i[1]);
	}
	
	for (auto& l : m)
	{
		sort(l.second.begin(),l.second.end());
	}


}