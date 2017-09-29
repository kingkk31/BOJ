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
	int stlen = 0;
	char stack[1000001];
	string str, boom;
	cin >> str >> boom;

	for (int i = 0; i < str.length(); i++)
	{
		stack[stlen++] = str[i];
		if (stack[stlen-1] == boom[boom.length() - 1])
		{
			bool ch = false;
			for (int j = 0; j < boom.length(); j++)
			{
				if (boom[j] != stack[stlen - boom.length() + j])
				{
					ch = true;
					break;
				}
			}
			if (!ch)
				stlen -= boom.length();
		}
		stack[stlen] = '\0';
	}

	stack[stlen] = '\0';
	
	if (stlen == 0)
		cout << "FRULA" << endl;
	else
		cout << stack << endl;

	return 0;
}