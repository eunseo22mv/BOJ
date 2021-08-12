#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[20]; // 12���� ������ ū �� 20���� �����

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0);

	for (int i = 0; i < 12; ++i) //12�� �Է� ����
	{
		int x, y; //�� ���� x, y�� �־����� x�� ������ x�� ������ �����ϴٴ� ���� �ǹ�
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	//������ ������ 3���̸鼭 �ش� ������ 3���� �͵� �� ������ ������ ���� ���� 6�� ��츦 ã���ֱ�

	for (int i = 1; i <= 12; ++i)
	{
		if (adj[i].size() == 3) //i�� ������ ������ ������ ����Ʈ�� ũ�Ⱑ 3�̶�� �� ���� ũ�Ⱑ 3�� ����̹Ƿ� �� ��츸 Ž��
		{
			int count = 0;
			count += adj[adj[i][0]].size(); //�ش� ������ ����� ������ ��(����Ʈ�� ũ��)
			count += adj[adj[i][1]].size();
			count += adj[adj[i][2]].size();
			if (count == 6) //6�̸� ����ī ��
			{
				cout << i; //���� ����ϰ� �ִ� ���� ��ȣ�� �������
				return 0;
			}
		}
	}
}