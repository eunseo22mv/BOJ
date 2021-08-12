#include <iostream>
#include <math.h>
using namespace std;

int n, r, c;
int result;

void recursion(int x, int y, int len) { // 재귀함수를 사용
    // x, y가 찾는 위치의 값이 같아질 때까지 반복
    if (y == r && x == c) {         // 찾는 좌표의 결과값 출력
        cout << result << endl;
        return;
    }
    // 길이를 더 이상 분할할 수 없으면 +1
    if (len == 1) {               // +1
        result++; 
        return;
    }
    // 탐색 중인 사분면에 찾는 위치가 있을 수 없으면 그 사분면의 크기만큼 result에 더하기
    if (!(y <= r && r < y + len && x <= c && c < x + len)) { //
        result += len * len;
        return;
    }
    recursion(x, y, len / 2);                       // 2사분면
    recursion(x + len / 2, y, len / 2);             // 1사분면
    recursion(x, y + len / 2, len / 2);             // 3사분면
    recursion(x + len / 2, y + len / 2, len / 2);   // 4사분면
}

int main() {
    cin >> n;            // 2의 n제곱 크기
    cin >> r;            // x좌표
    cin >> c;            // y좌표

    recursion(0, 0, pow(2, n));      // pow : 2의 n제곱

    return 0;
}