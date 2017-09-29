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
#pragma warning(disable:4996)
using namespace std;

typedef struct Color {
	int white;
	int blue;
	int red;

	Color()
	{
		white = 0;
		blue = 0;
		red = 0;
	}
};

int n, m;
vector<Color> color;

int solve(int pos, char c, vector<Color> color)
{
	if (pos == n-1)
		return color[pos].blue + color[pos].white;

	int cnt = 0;

	if (c == 'w')
	{
		int blue = color[pos].white + color[pos].red + solve(pos + 1, 'b', color);
		if (pos + 1 == n - 1)
			cnt = blue;
		else
		{
			int white = color[pos].blue + color[pos].red + solve(pos + 1, 'w', color);
			cnt = min(white, blue);
		}
	}
	else if (c == 'b')
	{
		int red = color[pos].blue + color[pos].white + solve(pos + 1, 'r', color);
		int blue = color[pos].white + color[pos].red + solve(pos + 1, 'b', color);
		cnt = min(red, blue);
	}
	else if (c == 'r')
		cnt = color[pos].blue + color[pos].white + solve(pos + 1, 'r', color);

	return cnt;
}

int main(void)
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		Color temp;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == 'W')
				temp.white++;
			else if (str[j] == 'B')
				temp.blue++;
			else
				temp.red++;
		}
		color.push_back(temp);
	}
	
	cout << color[0].blue + color[0].red + solve(1, 'w', color) << endl;
	
	return 0;
}