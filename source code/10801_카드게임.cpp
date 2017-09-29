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
	int a = 0, b = 0, aArr[10], bArr[10];
	for (int i = 0; i < 10; i++)
		cin >> aArr[i];
	for (int i = 0; i < 10; i++)
		cin >> bArr[i];

	for (int i = 0; i < 10; i++)
		if (aArr[i] > bArr[i])
			a++;
		else if (aArr[i] < bArr[i])
			b++;

	if (a > b)
		cout << "A" << endl;
	else if (a < b)
		cout << "B" << endl;
	else
		cout << "D" << endl;

	return 0;
}