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

bool pairSort(const pair<int, int> &left, const pair<int, int> &right)
{
	return left.second < right.second;
}

int main(void)
{
	vector<pair<int, int> > vt(8);
	for (int i = 0; i < 8; i++)
	{
		int num;
		cin >> num;
		vt[i] = make_pair(i + 1, num);
	}

	sort(vt.begin(), vt.end(), pairSort);
	
	vector<int> vt2;
	int total = 0;
	
	for (int i = 3; i < 8; i++)
		total += vt[i].second;

	cout << total << endl;
	for (int i = 3; i < 8; i++)
		vt2.push_back(vt[i].first);

	sort(vt2.begin(), vt2.end());
	for (int i = 0; i < vt2.size(); i++)
		cout << vt2[i] << " ";
	cout << endl;
	
	return 0;
}