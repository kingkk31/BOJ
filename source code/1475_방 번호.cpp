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
	int arr[9] = { 0 }, maxi = -1;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '6':
		case '9': arr[6]++; break;
		default: arr[(int)(str[i] - '0')]++;
		}
		
	}
	
	if (arr[6] % 2 == 0)
		arr[6] /= 2;
	else
		arr[6] = arr[6] / 2 + 1;

	for (int i = 0; i < 9; i++)
		maxi = max(maxi, arr[i]);

	cout << maxi << endl;

	return 0;
}