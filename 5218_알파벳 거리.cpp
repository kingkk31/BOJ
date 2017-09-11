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
	int n;
	cin >> n;
	while (n--)
	{
		string str1, str2;
		cin >> str1 >> str2;

		cout << "Distances: ";
		for (int i = 0; i < str1.length(); i++)
		{
			int x = (int)(str1[i] - 'A') + 1, y = (int)(str2[i] - 'A') + 1;
		
			if (y >= x)
				cout << y - x << " " ;
			else
				cout << (y + 26) - x << " ";
		}
		cout << endl;
	}

	return 0;
}