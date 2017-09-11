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
	int n;
	cin >> n;
	
	while (n--)
	{
		string str;
		cin >> str;
		int num = (int)(str[str.length() - 1] - '0');
		if (num % 2 == 0)
			cout << "even" << endl;
		else
			cout << "odd" << endl;
	}

	return 0;
}