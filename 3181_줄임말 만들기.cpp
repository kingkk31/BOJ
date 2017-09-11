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
	vector<string> vt;
	string str, temp = "";
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			vt.push_back(temp);
			temp = "";
		}
		else
			temp += str[i];
	}
	vt.push_back(temp);

	if(vt.size() > 0)
		cout << (char)(vt[0][0] - 32);
	for (int i = 1; i < vt.size(); i++)
	{
		if(vt[i] != "i" && vt[i] != "pa" && vt[i] != "te" && vt[i] != "ni" && vt[i] != "niti" && vt[i] != "a" && vt[i] != "ali" && vt[i] != "nego" && vt[i] != "no" && vt[i] != "ili")
			cout << (char)(vt[i][0] - 32);
	}

	return 0;
}