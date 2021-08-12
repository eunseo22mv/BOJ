#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

	int n, k;
	// 학생들의 이름 길이별로 큐 생성 (1~22)
	queue<int> q[21];
	long long cnt = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		// 학생을 입력받을 때마다 이름 길이에 해당하는 큐 탐색
		string input;
		cin >> input;

		int len = input.length();

		// 학생의  등수 차이가 k보다 큰 학생들 모두 pop
		while (!q[len].empty() && i - q[len].front() > k) {
			q[len].pop();
		}
		// 남아있는 큐의 원소의 개수 cnt
		cnt += q[len].size();
		q[len].push(i);
	}
	
	cout << cnt;
}