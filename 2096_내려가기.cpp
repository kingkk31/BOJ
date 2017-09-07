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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> vt1(3); //min
	vector<int> vt2(3); //max
	vector<int> temp(3);
	
	int f, s, t;
	cin >> f >> s >> t;

	vt1[0] = vt2[0] = f;
	vt1[1] = vt2[1] = s;
	vt1[2] = vt2[2] = t;

	for (int i = 1; i < n; i++)
	{
		int first, second, third;
		cin >> first >> second >> third;

		temp[0] = min(vt1[0], vt1[1]) + first;
		temp[1] = min(vt1[0], min(vt1[1], vt1[2])) + second;
		temp[2] = min(vt1[1], vt1[2]) + third;

		vt1[0] = temp[0];
		vt1[1] = temp[1];
		vt1[2] = temp[2];

		temp[0] = max(vt2[0], vt2[1]) + first;
		temp[1] = max(vt2[0], max(vt2[1], vt2[2])) + second;
		temp[2] = max(vt2[1], vt2[2]) + third;
		
		vt2[0] = temp[0];
		vt2[1] = temp[1];
		vt2[2] = temp[2];
	}

	cout << max(vt2[0], max(vt2[1], vt2[2])) << " " << min(vt1[0], min(vt1[1], vt1[2])) << endl;

	return 0;
}
