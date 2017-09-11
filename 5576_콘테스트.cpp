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
	vector<int> w(10);
	vector<int> k(10);

	for (int i = 0; i < 10; i++)
		cin >> w[i];
	for (int i = 0; i < 10; i++)
		cin >> k[i];
	
	sort(w.begin(), w.end());
	sort(k.begin(), k.end());

	cout << w[7] + w[8] + w[9] << " " << k[7] + k[8] + k[9] << endl;

	return 0;
}