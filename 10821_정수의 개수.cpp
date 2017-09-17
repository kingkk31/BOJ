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

	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == ',')
			cnt++;
	cout << cnt + 1 << endl;

	return 0;
}