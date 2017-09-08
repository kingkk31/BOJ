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
	vector<int> vt;

	for (int i = 1; i <= 5;i++)
	{
		string str;
		cin >> str;
		
		for (int j = 0; j < str.length()-2; j++)
		{
			if (str[j] == 'F' && str[j + 1] == 'B' && str[j + 2] == 'I')
			{
				vt.push_back(i);
				break;
			}
		}
	}

	if (vt.empty())
		cout << "HE GOT AWAY!" << endl;
	else
	{
		for (int i = 0; i < vt.size(); i++)
			cout << vt[i] << " ";
		cout << endl;
	}

	return 0;
}