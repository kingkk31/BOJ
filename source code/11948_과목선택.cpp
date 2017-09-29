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
	int total = 0;
	vector<int> science(4), society(2);
	
	for (int i = 0; i < 4; i++)
		cin >> science[i];
	for (int i = 0; i < 2; i++)
		cin >> society[i];

	sort(science.begin(), science.end());
	sort(society.begin(), society.end());

	for (int i = 1; i < 4; i++)
		total += science[i];
	total += society.back();
	cout << total << endl;

	return 0;
}