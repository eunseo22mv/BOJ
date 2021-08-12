#include <iostream>
#include <algorithm>

using namespace std;
int A[1000000];

int main() {
	int n;	// 빨대의 개수
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];
	sort(A, A + n);	// 빨대의 길이를 오름차순으로 정렬

	for (int i = n - 1; i >= 2; i--) {
		int a = A[i];		// 가장 긴 변의 길이
		int b = A[i - 1];
		int c = A[i - 2];
		if (a < b + c) {	// 삼각형 세 변의 조건에 부합하는지 확인
			cout << a + b + c;
			return 0;
		}
	}
	cout << "-1";
}