#include <stdio.h>

int candy[1001][1001];
int dp[1001][1001];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void) {

    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &candy[i][j]);  // 미로에 있는 사탕 수 입력

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            int result = 0;
            // dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] 세 가지 중 최댓값을 구하기
            result = max(dp[i - 1][j - 1], max(dp[i - 1][j],dp[i][j - 1]));
            dp[i][j] = result + candy[i][j];    // 앞 과정에서의 최대값 + 현재 위치 candy[i][j]의 값
        }


    printf("%d\n", dp[N][M]);
}
