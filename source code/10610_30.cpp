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
	string str;
	cin >> str;
	
	long long three = 0;
	int num[10] = { 0 };

	for (int i = 0; i < str.length(); i++) 
	{
		int temp = str[i] - '0';
		num[temp]++;
		three += temp;
	}

	if (num[0] != 0 && three % 3 == 0)
	{ 
		for (int i = 9; i >= 0; i--) 
			for (int j = 0; j < num[i]; j++)
				printf("%d", i);
		cout << endl;
	}
	else
		cout << -1 << endl;
	
	return 0;
}