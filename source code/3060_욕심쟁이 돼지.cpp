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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, *pig = new int[6], days = 0, sum = 0, *temp = new int[6];
		scanf("%d", &n);
		for (int i = 0; i < 6; i++)
		{
			scanf("%d", pig + i);
			sum += pig[i];
		}

		while (true)
		{
			days++;
			if (sum > n)
				break;

			sum = 0;
			for (int i = 0; i < 6; i++)
			{
				temp[i] = pig[i] + pig[(i + 1) % 6] + pig[(i + 7) % 6] + pig[(i + 3) % 6];
				sum += temp[i]; 
			}

			for (int i = 0; i < 6; i++)
				pig[i] = temp[i];
		}

		cout << days << endl;
		delete(pig);
		delete(temp);
	}

	return 0;
}