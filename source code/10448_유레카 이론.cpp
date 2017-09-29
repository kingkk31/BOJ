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
	int three[36];
	for (int i = 0; i < 36; i++)
	{
		int num = ((i+1)*(i + 2)) / 2;
		three[i] = num;
	}
	
	vector<int> vt;
	for (int i = 0; i < 36;i++)
		for (int j = i; j < 36; j++)
			for (int k = j; k < 36; k++)
			{
				int num = three[i] + three[j] + three[k];
				vt.push_back(num);
			}
	
	sort(vt.begin(), vt.end());
	
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		if (binary_search(vt.begin(), vt.end(), n))
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
