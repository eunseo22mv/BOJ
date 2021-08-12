#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int S[22][22];
bool selected[22];
int result = 100000000;

void dfs(int step, int counting) {

    // counting=n/2,  지금까지 선택 VS 선택 X -> 두 팀으로 나눠서 능력치 계산
    // min값이랑 비교, 저장 후 리턴
    int startValue = 0;
    int linkValue = 0;
    vector<int> startTeam;
    vector<int> linkTeam;

    if (counting == n / 2) {

        // 팀 분리
        for (int i = 0; i < n; i++) {
            if (selected[i] == true) { //start 팀
                startTeam.push_back(i);
            }
            else { // link 팀
                linkTeam.push_back(i);
            }
        }

        // 능력치 계산
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                startValue += S[startTeam[i]][startTeam[j]];
                linkValue += S[linkTeam[i]][linkTeam[j]];
            }
        }

        //최솟값 계산
        result = min(result, abs(startValue - linkValue));
        return;
    }

    // counting이 n/2보다 작으면 '선택' - 팀 선택은 지금까지 선택안한애들 중에 1개씩 재귀

    // 재귀 전 select = true
    // 재귀 후 select = false
    for (int i = step; i < n; i++) {
        if (selected[i] == false) {
            selected[i] = true;
            dfs(i, counting + 1);
            selected[i] = false;
        }
    }

}


int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }

    dfs(0, 0);

    cout << result << "\n";

    return 0;
}