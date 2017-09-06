#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <assert.h>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> vt;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vt.push_back(num);
	}

	sort(vt.begin(), vt.end());

	cout << vt.front()*vt.back() << endl;
	
	return 0;
}