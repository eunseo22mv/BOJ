#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

	int n, k;
	// �л����� �̸� ���̺��� ť ���� (1~22)
	queue<int> q[21];
	long long cnt = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		// �л��� �Է¹��� ������ �̸� ���̿� �ش��ϴ� ť Ž��
		string input;
		cin >> input;

		int len = input.length();

		// �л���  ��� ���̰� k���� ū �л��� ��� pop
		while (!q[len].empty() && i - q[len].front() > k) {
			q[len].pop();
		}
		// �����ִ� ť�� ������ ���� cnt
		cnt += q[len].size();
		q[len].push(i);
	}
	
	cout << cnt;
}