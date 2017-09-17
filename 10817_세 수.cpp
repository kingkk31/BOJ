#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stdio.h>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	vector<int> n;
	n.push_back(A);
	n.push_back(B);
	n.push_back(C);

	sort(n.begin(), n.end());

	cout << n[1];

	return 0;
}