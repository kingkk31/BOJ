#include <iostream>
#include <vector>

#define INF 20
using namespace std;

//상하좌우
int check[10][4] = { { 7, INF, INF, INF },
{ INF, 4, INF, 2 }, { INF, 5, 1, 3 },
{ INF, 6, 2, INF }, { 1, 7, INF, 5 },
{ 2, 8, 4, 6 }, { 3, 9, 5, INF },
{ 4, 0, INF, 8 }, { 5, INF, 7, 9 },
{ 6, INF, 8, INF } };

int N;
vector<vector<int> > cache;
int pwd(int start, int n) {
	if (n == N) return 1;

	int &ret = cache[start][n];

	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < 4; i++) {
		if (check[start][i] != INF){
			ret += pwd(check[start][i], n+1) % 1234567;
		}
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cache.assign(10, vector<int>(1001,-1));

		int pwdcnt = 0;

		for (int i = 0; i < 10; i++)
			pwdcnt += pwd(i, 1)%1234567;
			
		cout << pwdcnt%1234567 << endl;
	}
	return 0;
}