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

int main(void)
{
	int r, c;
	cin >> r >> c;

	vector<vector<char> > vt(r, vector<char>(c));
	vector<int> rank(10);
	for (int i = 0; i < r; i++) 
	{
		for (int j = 0; j < c; j++)
		{
			cin >> vt[i][j];

			if (vt[i][j] != '.' && vt[i][j] != 'F' & vt[i][j] != 'S')
				rank[(int)(vt[i][j] - '0')] = j;
		}
	}

	for (int i = 1; i < 10; i++)
	{
		vector<int> temp;
		int pos = 0;
		for (int j = 1; j < 10; j++)
			if (rank[i] < rank[j])
			{
				vector<int>::iterator itr = temp.begin();
				if (find(temp.begin(), temp.end(), rank[j]) == temp.end())
				{
					pos++;
					temp.push_back(rank[j]);
				}
			}
		cout << pos+1 << endl;
	}

	return 0;
}