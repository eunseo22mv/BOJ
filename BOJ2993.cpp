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
			// ���ڿ� �� �Լ� : compare ���
			// ans.compare(b)  :   ���� 0���� Ŭ ��� ans�� b���� ���������� �ڿ� �ִٴ� �ǹ�
		}
	}
	cout << ans;
}