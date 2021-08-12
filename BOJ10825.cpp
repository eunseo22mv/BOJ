#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct score {
    string name;
    int kor, eng, math;
};

// sort 함수에 사용할 함수
bool compare(score a, score b) {
    // 4. 국어==영어==수학 -> 이름 오름차순 정렬
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;

    // 3. 국어==영어 -> 수학 내림차순 정렬
    if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;

    // 2. 국어== -> 영어 오름차순 정렬
    if (a.kor == b.kor) return a.eng < b.eng;

    // 1. 국어 내림차순 정렬
    return a.kor > b.kor;
}

int main() {
    int N;
    cin >> N;

    vector<score> v(N);    // score 구조체 형식의 벡터

    for (int i = 0; i < N; i++)
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;

    sort(v.begin(), v.end(), compare); //sort함수 : v.begin() 부터 v.end를 compare 함수대로 정렬

    for (int i = 0; i < N; i++)
        cout << v[i].name << '\n';

}
