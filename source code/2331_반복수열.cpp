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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int a, p;
	cin >> a >> p;

	vector<int> vt;
	vt.push_back(a);

	while (true)
	{
		int num = a, temp = 0;
		while (num != 0)
		{
			temp += pow((num % 10), p);
			num /= 10;
		}

		for (int i = 0; i < vt.size(); i++)
		{
			if (temp == vt[i])
			{
				cout << i << endl;
				return 0;
			}
		}	

		vt.push_back(temp);
		a = temp;
	}
	
	return 0;
}