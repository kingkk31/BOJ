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

stack<char> strL, strR;
string str;
int n;
char command;

int main(void)
{
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		strL.push(str[i]);

	cin >> n;
	while (n--)
	{
		cin >> command;

		if (command == 'L') 
		{
			if (!strL.empty())
			{
				strR.push(strL.top());
				strL.pop();
			}
		}
		else if (command == 'D')
		{
			if (!strR.empty()) 
			{
				strL.push(strR.top());
				strR.pop();
			}
		}
		else if (command == 'B') 
		{
			if (!strL.empty())
				strL.pop();
		}
		else if (command == 'P') 
		{
			cin >> command;
			strL.push(command);
		}
	}

	while (!strL.empty()) 
	{
		strR.push(strL.top());
		strL.pop();
	}
	
	while (!strR.empty()) 
	{
		cout << strR.top();
		strR.pop();
	}
	cout << endl;

	return 0;
}
