#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
string ans;

void reverse(string& s, int i, int j) {		
	while (i < j) {
		swap(s[i], s[j]);
		i++;
		j--;
	}
}

int main() {
	string a;
	cin >> a;
	ans = a;
	int s = a.size();
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j + 1 < s; j++) {
			string b = a;
			reverse(b, 0, i);
			reverse(b, i + 1, j);
			reverse(b, j + 1, s - 1);
			if (ans.compare(b) > 0) ans = b;	
			// 문자열 비교 함수 : compare 사용
			// ans.compare(b)  :   값이 0보다 클 경우 ans가 b보다 사전적으로 뒤에 있다는 의미
		}
	}
	cout << ans;
}