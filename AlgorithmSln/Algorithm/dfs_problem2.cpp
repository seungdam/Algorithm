#include "pch.h"


int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);
    for (int enter = 0; enter < n; ++enter)
    {
        if (visited[enter] == false)
        {
           
            queue<int> bfsq;
            bfsq.push(enter);
            visited[enter] = true;
            
            while (!bfsq.empty())
            {
                int from = bfsq.front();
                bfsq.pop();
                for (int to = 0; to < computers[from].size(); ++to)
                {
                    if (computers[from][to] != 1) continue;
                    if (visited[to]) continue;
                    visited[to] = true;
                    bfsq.push(to);
                }
            }
            answer += 1;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> v{ {1, 1, 0} ,{1, 1, 0}, { 0, 0, 1 } };
    cout << solution(3, v);
}