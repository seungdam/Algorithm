#include "pch.h"
#include <sstream>
#include <algorithm>

// idea 최고 차수의 계수가 가장 큰 값 순서대로 나열하는 방법
// 만약 두 차수가 같다면, 다음 차수가 큰 순서대로 진행
// 왜 키워드가 정렬일까..
string solution(vector<int>& numbers)
{
	
	vector<string> sv;
	for (auto i : numbers)
	{
		ostringstream oss;
		oss << i;
		sv.push_back(oss.str());
	}

	sort(sv.begin(), sv.end(), [](string a, string b) { return a + b > b + a; });

	ostringstream os;
	for (const auto& i : sv)
	{
		os << i;
	}
	if (os.str()[0] == '0') return string{"0"};
	return os.str();
}


int main()
{
	vector<int> n{ 0,0,0 }; // 54333042303321
	cout << solution(n);
	
}