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
            scanf("%d", &candy[i][j]);  // �̷ο� �ִ� ���� �� �Է�

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            int result = 0;
            // dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] �� ���� �� �ִ��� ���ϱ�
            result = max(dp[i - 1][j - 1], max(dp[i - 1][j],dp[i][j - 1]));
            dp[i][j] = result + candy[i][j];    // �� ���������� �ִ밪 + ���� ��ġ candy[i][j]�� ��
        }


    printf("%d\n", dp[N][M]);
}
