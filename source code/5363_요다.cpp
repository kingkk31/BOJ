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
	int n;
	cin >> n;

	while (n--)
	{
		string str;
		vector<string> vt;

		while (str != "\n")
		{
			cin >> str;
			vt.push_back(str);
			str = getchar();
		}

		if (vt.size() <= 2)
		{
			for (int i = 0; i < vt.size(); i++)
				cout << vt[i] << " ";
			cout << endl;
		}
		else
		{
			for (int i = 2; i < vt.size(); i++)
				cout << vt[i] << " ";
			cout << vt[0] << " " << vt[1] << endl;
		}
	}

	return 0;
}