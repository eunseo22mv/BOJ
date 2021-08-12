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

	// ���� �ֱٿ� �⸧�� ���� ���� min���� �ΰ� ���� ������ �⸧���� ��
	for(int i = 0; i < N - 1; i++) { 
		if(node[i] < min) { 
			min = node[i];	// min�� ��� ����
		} 
		target += link[i] * min; //  (min ����) * (�ٷ� ���� ���ñ����� �Ÿ�)
	} 
	cout << target; 
	return 0; 
}

