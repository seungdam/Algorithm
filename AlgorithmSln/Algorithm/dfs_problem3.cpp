#include "pch.h"
using namespace std;
// 최단거리 --> bfs

struct pos
{
    int x;
    int y;


    pos operator+(const pos& rhs)
    {
        return pos{ rhs.x + x, y + rhs.y };
    }
    bool operator==(const pos& rhs) const
    { 
        return ((rhs.x == x) && (rhs.y == y)); 
    }
  
};

pos front[4]
{
    { 1,  0}, // 우
    { 0,  1},  // 하
    { -1, 0 }, // 좌
    { 0, -1 }, // 상
};


int solution(vector<vector<int>>& maps)
{
    pos cur = { 0,0 };
    pos dest;

    int map_h = maps.size() - 1;
    int map_w = maps[0].size() - 1;
    dest.x = map_w;
    dest.y = map_h;
    
    int answer = 0;
    queue<pos> bfsq;
    bool visited[100][100]{ false, };
    visited[0][0] = true;
   

    bfsq.push(cur);
    while (!bfsq.empty())
    {
        cur = bfsq.front();
        bfsq.pop();
        if (cur == dest) break;

        for (auto dir : front)
        {
            pos next = cur + dir;
            if (next.y < 0 || next.x < 0 || next.y > dest.y || next.x > dest.x) continue;
            if (maps[next.y][next.x] == 0) continue;
            if (visited[next.y][next.x]) continue;
            visited[next.y][next.x] = true;
            bfsq.push(next);
            maps[next.y][next.x] += maps[cur.y][cur.x]; // 누적합을 활용해 수정한 방식
            // ++answer 
            // 내 첫번째 풀이는 다음 코드로 했는데 이렇게 하니, 우회하는 경로의 횟수도 포함시켜 최장거리값이 리턴된다.
        }
    }

    if (maps[dest.y][dest.x] == 1) return -1;
    return maps[dest.y][dest.x];
};

int main()
{
    vector<vector<int>> v{ {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1} };
    
    cout << solution(v);
    cout << "\n";
    for (auto i : v)
    {
        for (auto k : i) cout << k << " ";
        cout << "\n";
    }
   
}
