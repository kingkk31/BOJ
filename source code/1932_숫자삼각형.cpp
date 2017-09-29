#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int triangle[500][500];//�־��� �ﰢ��
int cache[500][500];//�ִ밪 �����

int check(int i, int j, int N)
{
	if (i == (N - 1))
		return triangle[i][j]; //�ǳ� ���� �� ��ȯ 
	
	int &ret = cache[i][j];

	if (ret != -1) //�̹� �˻��ߴٸ� ��ȯ
		return ret;

	return ret = max(check(i + 1, j, N), check(i + 1, j + 1, N)) + triangle[i][j]; // �Ʒ� �� ���� �� ū ���� ���� �� ��ȯ
}

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> triangle[i][j];
			cache[i][j] = -1;
		}
	}
	
	cout << check(0, 0, N)<<endl;
	
	return 0;
}