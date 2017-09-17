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
	int n, m;
	cin >> n >> m;

	vector<string> vt(n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		vt[i] = str;
	}

	for (int i = 0; i < n; i++)
		cout << vt[i] << endl;
	
	return 0;
}