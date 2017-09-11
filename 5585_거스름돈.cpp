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
	int money[6] = { 500, 100, 50, 10, 5, 1 };
	int pay, cnt = 0;
	cin >> pay;
	pay = 1000 - pay;

	for (int i = 0; i < 6; i++)
	{
		while (pay >= money[i])
		{
			pay -= money[i];
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}