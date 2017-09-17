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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	string str, temp1, temp2;
	cin >> str;

	temp1 = str.substr(0, str.size() / 2);
	reverse(str.begin(), str.end());
	temp2 = str.substr(0, str.size() / 2);
	
	bool ch = false;

	for (int i = 0; i < temp1.size(); i++)
	{
		if (temp1[i] != temp2[i])
		{
			ch = true;
			break;
		}
	}

	if (ch)
		cout << 0 << endl;
	else
		cout << 1 << endl;

	return 0;
}
