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

int main(void)
{
	int t, n, m;
	scanf("%d", &t);
	
	map<int, string> num;
	num[1] = "Yakk"; num[2] = "Doh"; num[3] = "Seh"; num[4] = "Ghar"; num[5] = "Bang"; num[6] = "Sheesh";
	map<int, string> equal;
	equal[1] = "Habb Yakk"; equal[2] = "Dobara"; equal[3] = "Dousa"; equal[4] = "Dorgy"; equal[5] = "Dabash"; equal[6] = "Dosh";

	for (int i = 1; i <= t; i++)
	{
		scanf("%d %d", &n, &m);
		if (n == m)
			cout << "Case " << i<< ": " << equal[n] << endl;
		else
		{
			if ((n == 6 & m == 5) || (n == 5 & m == 6))
				cout << "Case " << i << ": " << "Sheesh Beesh" << endl;
			else
			{
				if (n < m) swap(n, m);
				cout << "Case " << i << ": " << num[n] << " " << num[m] << endl;
			}
		}
	}
	
	return 0;
}