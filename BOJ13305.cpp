#include <iostream> 
#include <vector> 
using namespace std; 
int main(void) 
{ 
	int N; 
	long long link[100001]; 
	long long node[100001]; 
	scanf("%d", &N); 
	for(int i = 0; i < N - 1; i++) { 
		cin >> link[i];
	} 
	for(int i = 0; i < N; i++) { 
		cin >> node[i]; 
	} 
	long long target = 0; 
	long long min = node[0]; 

	// 가장 최근에 기름을 넣은 곳을 min으로 두고 현재 도시의 기름값과 비교
	for(int i = 0; i < N - 1; i++) { 
		if(node[i] < min) { 
			min = node[i];	// min을 계속 갱신
		} 
		target += link[i] * min; //  (min 가격) * (바로 다음 도시까지의 거리)
	} 
	cout << target; 
	return 0; 
}

