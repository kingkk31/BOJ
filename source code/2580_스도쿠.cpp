#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#include <time.h>
#include <cctype>
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int rows[9][10], cols[9][10], boxes[9][10];
vector<vector<int> > vt;
vector<pair<int, int> > blank;
bool flag;

//n번째 박스
int boxNum(int y, int x)
{
	if (0 <= y && y <= 2)
	{
		if (0 <= x && x <= 2)
			return 0;
		else if (3 <= x && x <= 5)
			return 1;
		else
			return 2;
	}
	else if (3 <= y && y <= 5)
	{
		if (0 <= x && x <= 2)
			return 3;
		else if (3 <= x && x <= 5)
			return 4;
		else
			return 5;
	}
	else
	{
		if (0 <= x && x <= 2)
			return 6;
		else if (3 <= x && x <= 5)
			return 7;
		else
			return 8;
	}
}

void solve(int pos)
{
	if (flag)
		return;

	//검사 완료 시
	if (pos >= blank.size())
	{
		for (int i = 0; i < 9; i++)
			for (int j = 1; j <= 9; j++)
				if (rows[i][j] != 1 || cols[i][j] != 1 || boxes[i][j] != 1)
					return;
		
		flag = true;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				printf("%d ", vt[i][j]);
			printf("\n");
		}
		return;
	}

	int y = blank[pos].first, x = blank[pos].second;
	int box = boxNum(y, x);
	
	for (int i = 1; i <= 9; i++)
	{
		if (rows[y][i] == 0 && cols[x][i] == 0 && boxes[box][i] == 0)
		{
			rows[y][i] = 1, cols[x][i] = 1, boxes[box][i] = 1;
			vt[y][x] = i;
			solve(pos + 1);
			vt[y][x] = 0;
			rows[y][i] = 0, cols[x][i] = 0, boxes[box][i] = 0;
		}
	}
}

int main(void)
{
	memset(rows, 0, sizeof(rows));
	memset(cols, 0, sizeof(cols));
	memset(boxes, 0, sizeof(boxes));
	flag = false;
	vt = vector<vector<int> >(9, vector<int>(9));

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &vt[i][j]);
			if (vt[i][j] == 0)
				blank.push_back(make_pair(i, j));
			else
				rows[i][vt[i][j]] = 1, cols[j][vt[i][j]] = 1, boxes[boxNum(i, j)][vt[i][j]] = 1;
		}
	
	solve(0);

	return 0;
}