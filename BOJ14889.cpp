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

    // counting=n/2,  ���ݱ��� ���� VS ���� X -> �� ������ ������ �ɷ�ġ ���
    // min���̶� ��, ���� �� ����
    int startValue = 0;
    int linkValue = 0;
    vector<int> startTeam;
    vector<int> linkTeam;

    if (counting == n / 2) {

        // �� �и�
        for (int i = 0; i < n; i++) {
            if (selected[i] == true) { //start ��
                startTeam.push_back(i);
            }
            else { // link ��
                linkTeam.push_back(i);
            }
        }

        // �ɷ�ġ ���
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                startValue += S[startTeam[i]][startTeam[j]];
                linkValue += S[linkTeam[i]][linkTeam[j]];
            }
        }

        //�ּڰ� ���
        result = min(result, abs(startValue - linkValue));
        return;
    }

    // counting�� n/2���� ������ '����' - �� ������ ���ݱ��� ���þ��Ѿֵ� �߿� 1���� ���

    // ��� �� select = true
    // ��� �� select = false
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