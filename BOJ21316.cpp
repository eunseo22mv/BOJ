#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[20]; // 12보다 적당히 큰 수 20으로 잡아줌

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0);

	for (int i = 0; i < 12; ++i) //12번 입력 받음
	{
		int x, y; //두 정수 x, y가 주어지면 x번 정점과 x번 정점이 인접하다는 것을 의미
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	//인접한 정점이 3개이면서 해당 정점이 3개인 것들 중 인접한 정점의 수의 합이 6인 경우를 찾아주기

	for (int i = 1; i <= 12; ++i)
	{
		if (adj[i].size() == 3) //i번 정점과 인접한 정점의 리스트의 크기가 3이라는 건 벡터 크기가 3인 경우이므로 그 경우만 탐색
		{
			int count = 0;
			count += adj[adj[i][0]].size(); //해당 정점과 연결된 정점의 수(리스트의 크기)
			count += adj[adj[i][1]].size();
			count += adj[adj[i][2]].size();
			if (count == 6) //6이면 스피카 별
			{
				cout << i; //현재 출력하고 있는 정점 번호를 출력해줌
				return 0;
			}
		}
	}
}