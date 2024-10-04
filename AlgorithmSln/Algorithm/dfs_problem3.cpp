#include "pch.h"
using namespace std;
// �ִܰŸ� --> bfs

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
    { 1,  0}, // ��
    { 0,  1},  // ��
    { -1, 0 }, // ��
    { 0, -1 }, // ��
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
            maps[next.y][next.x] += maps[cur.y][cur.x]; // �������� Ȱ���� ������ ���
            // ++answer 
            // �� ù��° Ǯ�̴� ���� �ڵ�� �ߴµ� �̷��� �ϴ�, ��ȸ�ϴ� ����� Ƚ���� ���Խ��� ����Ÿ����� ���ϵȴ�.
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
