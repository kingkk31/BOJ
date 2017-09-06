#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
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
	char a;
	vector<int> vt;

	while (1)
	{
		a = getchar();
		if (a == '\n')
			break;
		
		vt.push_back((int)a - '0');
	}

	sort(vt.begin(), vt.end(), greater<int>());

	for (int i = 0; i < vt.size(); i++)
		cout << vt[i];
	
	return 0;
}
