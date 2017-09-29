#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int n;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
		return true;

	return false;
}

int main(void)
{
	cin >> n;

	vector<string> vt;
	vector<string> open;
	
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vt.push_back(str);
	}

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		open.push_back(str);
	}

	bool mine = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (open[i][j] == 'x')
			{
				if (vt[i][j] == '*')
				{
					if (!mine)
						mine = true;
				}
			}
		}
	}
	//지뢰 오픈 체크

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (open[i][j] == 'x')
			{
				if (vt[i][j] == '*')
				{
					if (mine)
						cout << '*';
				}
				else
				{
					int cnt = 0;

					for (int k = 0; k < 8; k++)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];

						if (isRange(ny, nx) && vt[ny][nx] == '*')
							cnt++;
					}

					cout << cnt;
				}
			}
			else
			{
				if (vt[i][j] == '*')
				{
					if (mine)
						cout << '*';
					else
						cout << '.';
				}
				else
					cout << '.';
			}
		}

		cout << endl;
	}


	return 0;
}
