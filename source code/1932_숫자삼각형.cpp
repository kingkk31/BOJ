#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int triangle[500][500];//주어진 삼각형
int cache[500][500];//최대값 저장용

int check(int i, int j, int N)
{
	if (i == (N - 1))
		return triangle[i][j]; //맨끝 도착 시 반환 
	
	int &ret = cache[i][j];

	if (ret != -1) //이미 검사했다면 반환
		return ret;

	return ret = max(check(i + 1, j, N), check(i + 1, j + 1, N)) + triangle[i][j]; // 아래 두 숫자 중 큰 수에 더한 후 반환
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