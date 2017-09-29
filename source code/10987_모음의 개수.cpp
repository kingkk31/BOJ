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
	int cnt = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case'a':
		case'e':
		case'i':
		case'o':
		case'u':
			cnt++;
		default:
			break;
		}
	}

	cout << cnt << endl;
	
	return 0;
}