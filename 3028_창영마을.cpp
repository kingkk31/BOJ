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
	int cup = 1;
	string str;
	cin >> str;

	for (int i = 0; i < str.length();i++)
		switch(str[i])
		{
		case 'A' : 
			if (cup == 1)
				cup = 2;
			else if (cup == 2)
				cup = 1;
			break;
		case 'B':
			if (cup == 2)
				cup = 3;
			else if (cup == 3)
				cup = 2;
			break;
		case 'C':
			if (cup == 1)
				cup = 3;
			else if (cup == 3)
				cup = 1;
			break;
		}

	cout << cup << endl;

	return 0;
}