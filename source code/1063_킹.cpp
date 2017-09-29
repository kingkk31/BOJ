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
#pragma warning(disable:4996)
using namespace std;

//R L B T RT LT RB LB
int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

map<string, int> m;

bool isRange(char y, char x)
{
	if ('1' <= y && y <= '8' && 'A' <= x && x <= 'H')
		return true;

	return false;
}

int main(void)
{
	//R L B T RT LT RB LB
	m["R"] = 0;
	m["L"] = 1;
	m["B"] = 2;
	m["T"] = 3;
	m["RT"] = 4;
	m["LT"] = 5;
	m["RB"] = 6;
	m["LB"] = 7;

	string king, stone;
	int n;
	cin >> king >> stone >> n;

	int ky = king[1];
	int kx = king[0];
	int sy = stone[1];
	int sx = stone[0];

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		ky = king[1] + dy[m[str]];
		kx = king[0] + dx[m[str]];
		
		if (isRange(ky, kx))
		{
			if (ky == stone[1] && kx == stone[0])
			{
				sy = stone[1] + dy[m[str]];
				sx = stone[0] + dx[m[str]];

				if (isRange(sy, sx)) 
				{
					king[0] = kx;
					king[1] = ky;
					stone[0] = sx;
					stone[1] = sy;
				}
			}
			else
			{
				king[0] = kx;
				king[1] = ky;
			}
		}
	}

	cout << king[0] << king[1] << endl;
	cout << stone[0] << stone[1] << endl;

	return 0;
}