#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	
	int vt[2][100001];
	int score[2][100001];

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
	
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < n; b++)
				scanf("%d", &score[a][b]);
			
		vt[0][0] = score[0][0];
		vt[1][0] = score[1][0];
	
		for (int j = 1; j<n; j++)
		{
			vt[0][j] = max(vt[0][j - 1], score[0][j] + vt[1][j - 1]);
			vt[1][j] = max(vt[1][j - 1], score[1][j] + vt[0][j - 1]);
		}

		printf("%d\n", max(vt[1][n - 1], vt[0][n - 1]));
	}

	return 0;
}
