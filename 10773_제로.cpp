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
	vector<int> vt;
	int n, total = 0;
	cin >> n;
	
	while (n--)
	{
		int num;
		cin >> num;

		if (num == 0)
			vt.pop_back();
		else
			vt.push_back(num);
	}
	
	for (int i = 0; i < vt.size(); i++)
		total += vt[i];
		
	cout << total << endl;

	return 0;
}