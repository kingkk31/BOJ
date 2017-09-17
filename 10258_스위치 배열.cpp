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
	int n;
	cin >> n;

	for (int q = 0; q < n; q++)
	{
		char str[32];
		scanf("%s", str);
		
		int siz = strlen(str);
		str[siz] = '\0';

		char temp[32];
		for (int i = 0; i < siz; i++)
			temp[i] = '0';

		temp[siz] = '\0';

		int i = 0;
		while (str[i] == '0')
			i++;

		unsigned long long cnt = 0;

		for (i; i < siz; i++)
		{
			if (str[i] == temp[i])
				continue;

			cnt += pow(2, siz - i - 1);
			temp[i] = '1';
			temp[i + 1] = '1';
		}

		printf("%llu\n", cnt);
	}

	return 0;
}
