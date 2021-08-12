#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;

	cout.precision(10);		// 소수점 자리 수 고정
	cout << a / b << endl;

	return 0;
}