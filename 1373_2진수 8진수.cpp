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
	string num;
	cin >> num;

	vector<int> vt;
	vector<int> total;

	for (int i = 0; i < num.length(); i++)
		vt.push_back((int)num[i] - '0');
	
	int siz = vt.size() % 3;

	if (siz == 2)
		vt.insert(vt.begin(), 0);
	else if (siz == 1)
		for (int i = 0; i < 2;i++)
			vt.insert(vt.begin(), 0);

	siz = vt.size();

	while (siz != 0)
	{
		int part = vt.size() - siz;
		int sum = 0;

		int f=0, s=0, t=0;
		if(vt[part] == 1)
			f = pow((double)2, 2);
		if (vt[part+1] == 1)
			s = pow((double)2, 1);
		if (vt[part+2] == 1)
			t = pow((double)2, 0);
		
		sum += (f+s+t);
		total.push_back(sum);

		siz -= 3;
	}

	for (int i = 0; i < total.size(); i++)
		cout << total[i];

	return 0;
}