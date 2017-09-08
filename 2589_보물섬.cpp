#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cache[51][51];
vector<string> str;
int N, M;

bool isRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M)
		return true;
	return false;
}

int BFS(int y, int x) 
{
	queue<pair<int, int> > qu;
	memset(cache, -1, sizeof(cache));
	qu.push(pair<int, int>(y, x));
	cache[y][x] = 0;

	int ret = -1;

	while (!qu.empty()) 
	{
		pair<int, int> place = qu.front();
		qu.pop();

		for (int i = 0; i<4; ++i) 
		{
			int nextY = place.first + dy[i];
			int nextX = place.second + dx[i];
			
			if (!isRange(nextY, nextX)) 
				continue;
			
			if (cache[nextY][nextX] == -1 && str[nextY][nextX] == 'L') 
			{
				cache[nextY][nextX] = cache[place.first][place.second] + 1;
				ret = max(ret, cache[nextY][nextX]);
				qu.push(make_pair(nextY, nextX));
			}
		}
	}

	return ret;
}

int main(void) 
{
	cin>>N>>M;

	str.resize(N);

	for (int i = 0; i<N; ++i) 
		cin >> str[i];

	int check = -1;

	for (int i = 0; i<N; ++i)
		for (int j = 0; j<M; ++j)
			if (str[i][j] == 'L')
				check = max(check, BFS(i, j));

	cout << check << endl;

	return 0;
}