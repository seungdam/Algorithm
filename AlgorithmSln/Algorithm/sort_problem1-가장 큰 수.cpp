#include "pch.h"
#include <sstream>
#include <algorithm>

// idea �ְ� ������ ����� ���� ū �� ������� �����ϴ� ���
// ���� �� ������ ���ٸ�, ���� ������ ū ������� ����
// �� Ű���尡 �����ϱ�..
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