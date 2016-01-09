#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stdio.h>
using namespace std;

int N, M;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M)
		return true;
	return false;
}

int main(void)
{
	cin >> N >> M;

	vector<vector<char> > board;
	vector<vector<int> > cache(N, vector<int>(M, 10001));
	board.assign(N, vector<char>(M, '0'));
	queue<pair<int, int> > maze;
		
	for (int y = 0; y < N; y++) {
		string i;
		cin >> i;
		for (int x = 0; x < M; x++) {
			board[y][x] = i[x];
		}
	}

	maze.push(make_pair(0, 0));
	cache[0][0] = 1;

	while (!maze.empty()) 
    {
		int a = maze.front().first;
		int b = maze.front().second;
		maze.pop();
		board[a][b] = 0;

		for (int i = 0; i < 4; i++)
        {
			int nextX = b + dx[i];
			int nextY = a + dy[i];

			if (isRange(nextY, nextX) && board[nextY][nextX] == '1' && cache[nextY][nextX] > cache[a][b] + 1)
            {
				maze.push(make_pair(nextY, nextX));
				cache[nextY][nextX] = cache[a][b] + 1;
			}
		}			
	}

	cout << cache[N-1][M-1] << endl;
	return 0;
}
