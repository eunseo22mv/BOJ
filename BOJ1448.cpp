#include <iostream>
#include <algorithm>

using namespace std;
int A[1000000];

int main() {
	int n;	// ������ ����
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];
	sort(A, A + n);	// ������ ���̸� ������������ ����

	for (int i = n - 1; i >= 2; i--) {
		int a = A[i];		// ���� �� ���� ����
		int b = A[i - 1];
		int c = A[i - 2];
		if (a < b + c) {	// �ﰢ�� �� ���� ���ǿ� �����ϴ��� Ȯ��
			cout << a + b + c;
			return 0;
		}
	}
	cout << "-1";
}