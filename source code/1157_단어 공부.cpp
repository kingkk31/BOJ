#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	vector<int> al(26,0);
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		int small = (int)str[i] - 'a';
		int big = (int)str[i] - 'A';

		if (0 <= small && small < 26)
			al[small]++;
		if (0 <= big && big < 26)
			al[big]++;
	}

	vector<int> temp(al.begin() + 0, al.begin() + 26);
	sort(temp.begin(), temp.end());

	vector<char> check;

	for (int i = 0; i < 26; i++)
	{
		if (al[i] == temp.back())
			check.push_back((char)(i + 'A'));
	}

	if (check.size() > 1)
		cout << '?' << endl;
	else
		cout << check.front() << endl;
	
	return 0;
}