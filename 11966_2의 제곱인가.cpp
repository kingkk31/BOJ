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
#include <cctype>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n, i = 0;
	cin >> n;
	
	while (n > (int)pow((double)2, i)) i++;

	if (n == (int)pow((double)2, i))
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}