#include <iostream>
#include <math.h>
using namespace std;

int n, r, c;
int result;

void recursion(int x, int y, int len) { // ����Լ��� ���
    // x, y�� ã�� ��ġ�� ���� ������ ������ �ݺ�
    if (y == r && x == c) {         // ã�� ��ǥ�� ����� ���
        cout << result << endl;
        return;
    }
    // ���̸� �� �̻� ������ �� ������ +1
    if (len == 1) {               // +1
        result++; 
        return;
    }
    // Ž�� ���� ��и鿡 ã�� ��ġ�� ���� �� ������ �� ��и��� ũ�⸸ŭ result�� ���ϱ�
    if (!(y <= r && r < y + len && x <= c && c < x + len)) { //
        result += len * len;
        return;
    }
    recursion(x, y, len / 2);                       // 2��и�
    recursion(x + len / 2, y, len / 2);             // 1��и�
    recursion(x, y + len / 2, len / 2);             // 3��и�
    recursion(x + len / 2, y + len / 2, len / 2);   // 4��и�
}

int main() {
    cin >> n;            // 2�� n���� ũ��
    cin >> r;            // x��ǥ
    cin >> c;            // y��ǥ

    recursion(0, 0, pow(2, n));      // pow : 2�� n����

    return 0;
}