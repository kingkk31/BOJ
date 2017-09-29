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
	int arr[5];
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	for (int i = 0; i < 5; i++)
	{
		int flag = 0;
		for (int j = 0; j < 4; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag++;
				swap(arr[j], arr[j + 1]);
				printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
			}
		}
		if (flag == 0)
			break;
	}

	return 0;
}