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
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	char str;

	int num = 0;

	while (1)
	{
		str = getchar();
		
		if (str == '#')
			break;

		if (str == 'e')
		{
			if (num % 2 == 0)
				cout << 0;
			else
				cout << 1;
			
			num = 0;
			continue;
		}
		else if (str == 'o')
		{
			if (num % 2 == 0)
				cout << 1;
			else
				cout << 0;

			num = 0;
			continue;
		}
		else
		{
			if (str == '1')
				num++;

			cout << str;
		}		
	}

	return 0;
}