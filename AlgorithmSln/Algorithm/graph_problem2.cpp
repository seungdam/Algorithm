#include "pch.h"
#include <thread>

int mysol(int n, vector<vector<int>> results)
{
	int answer = 0;
	
	vector<vector<int>> lresult(n);
	vector<vector<int>> wresult(n);
	
	for (auto i : results)
	{
		lresult[i[0] - 1].push_back(i[1] - 1); // �ڽſ��� �й��� ��� ���
		wresult[i[1] - 1].push_back(i[0] - 1); // �ڽſ��� ������ ��� ���
	}

	

	vector<int> mc(n,0);

	// �ڽſ��� �й��� ����� ���� �ʺ� �켱 Ž�� �����ϸ� 
		// ���� ���� üũ --> �ڽŰ� ���õ� ��⸸ �߰��ؾ��ϹǷ� �湮�� ��忡 ���ؼ��� ó������ X
		//       -> 5
		// 3 -> 2 
		//       -> 4
		// ���� 4�� 5�� ��� ���δ� �߿����� X
		// ���� bfs + ���� bfs = ��ü �ο� �� - 1�̸� ���� ok
	

	for (int i = 0; i < lresult.size(); ++i)
	{
		
			vector<bool> discovered(n, false);
			queue<int> bfsq;
			bfsq.push(i);
			while (!bfsq.empty())
			{
				int from = bfsq.front();
				bfsq.pop();
				discovered[from] = true;
				
				for (auto to : lresult[from])
				{
					if (discovered[to]) continue;
					discovered[to] = true;
					mc[i] += 1; // count edge
					bfsq.push(to);
				}
			}
	}

	for (int i = 0; i < wresult.size(); ++i)
	{

		vector<bool> discovered(n, false);
		queue<int> bfsq;
		bfsq.push(i);
		while (!bfsq.empty())
		{
			int from = bfsq.front();
			bfsq.pop();
			discovered[from] = true;

			for (auto to : wresult[from])
			{
				if (discovered[to]) continue;
				discovered[to] = true;
				mc[i] += 1; // count edge
				bfsq.push(to);
			}
		}
	}
	
	answer = count(mc.begin(), mc.end(), n - 1);

	return answer;
}

void myprint(bool(*a)[101], int px, int py, int size = 10)
{
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			
			if (a[y][x]) cout << "\033[1;31m��";
			else if ((px) == x && (py) == y) cout << "\033[1;35m��";
			else cout << "\033[1;33m��";
			
		}
		cout << "\n";
	}
	cout << "\n";
}

int solution(int n, vector<vector<int>> results) 
{
	int answer = 0;
	bool arr[101][101];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < results.size(); i++) 
	{
		int from = results[i][0] - 1;
		int to =   results[i][1] - 1;
		arr[from][to] = true; // �¸� ���� ���
	}

	myprint(arr,-1,-1, n);

	for (int k = 0; k <= n; k++) 
	{
		for (int i = 0; i <= n; i++) 
		{
			for (int j = 0; j <= n; j++) 
			{
				if (arr[i][k] && arr[k][j]) arr[i][j] = true;
				myprint(arr,k,j);
				std::this_thread::sleep_for(0.6s);
			}
		}
	}
	for (int i = 0; i <= n; i++) 
	{
		int cnt = 0;
		for (int j = 0; j <= n; j++)
		{
			cnt += (arr[i][j] + arr[j][i]);
		}
		if (cnt == n - 1) answer++;
	}
	return answer;
}

int main()
{

	vector<vector<int>> a = { {4, 3},{4, 2},{3, 2}};
	cout <<  solution(3, a);

}