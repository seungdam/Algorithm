#include "pch.h"


int cnt;
int target_num = 0;

void DFS(const vector<int>& v, int icnt, int acc)
{
    int cidx = icnt;
    if (cidx == v.size())
    {
        cout << acc << "\n";
        if (acc == target_num)
        {
            ++cnt;
        }
        return;
    }
    DFS(v, cidx + 1, acc + v[cidx]);
    DFS(v, cidx + 1, acc - v[cidx]);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    target_num = target;
    DFS(numbers, 0, 0);
    return cnt;
}

int main()
{
    vector<int> v(5, 1);
    auto i = solution(v, 3);
    cout << i;
}