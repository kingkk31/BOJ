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
	int total = 0;
	int n;
	char num;

	cin >> n;
	num = getchar();
	
	for (int i = 0; i < n; i++)
	{
		num = getchar();
		total += (int)(num - '0');
	}

	cout << total << endl;

	return 0;
}