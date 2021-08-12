#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct score {
    string name;
    int kor, eng, math;
};

// sort �Լ��� ����� �Լ�
bool compare(score a, score b) {
    // 4. ����==����==���� -> �̸� �������� ����
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;

    // 3. ����==���� -> ���� �������� ����
    if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;

    // 2. ����== -> ���� �������� ����
    if (a.kor == b.kor) return a.eng < b.eng;

    // 1. ���� �������� ����
    return a.kor > b.kor;
}

int main() {
    int N;
    cin >> N;

    vector<score> v(N);    // score ����ü ������ ����

    for (int i = 0; i < N; i++)
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;

    sort(v.begin(), v.end(), compare); //sort�Լ� : v.begin() ���� v.end�� compare �Լ���� ����

    for (int i = 0; i < N; i++)
        cout << v[i].name << '\n';

}
