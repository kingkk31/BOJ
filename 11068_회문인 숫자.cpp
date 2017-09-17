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

int main(void)
{
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		int n;
		scanf("%d", &n);
		bool wh = false;

		for (int i = 2; i <= 64; i++)
		{
			vector<int> vt;
			int temp = n;
			
			while (temp != 0)
			{
				vt.push_back(temp%i);
				temp /= i;
			}

			bool ch = false;
			for (int a = 0; a < (vt.size() / 2); a++)
			{
				if (vt[a] != vt[vt.size() - 1 - a])
				{
					ch = true;
					break;
				}
			}

			if (!ch)
			{
				wh = true;
				break;
			}
		}
		if (wh)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}
