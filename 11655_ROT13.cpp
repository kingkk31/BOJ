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
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			continue;

		if (('a' <= str[i] && str[i] <= 'm') || ('A' <= str[i] && str[i] <= 'M'))
			str[i] += 13;
		else if (('n' <= str[i] && str[i] <= 'z') || ('N' <= str[i] && str[i] <= 'Z'))
			str[i] -= 13;
	}

	cout << str << endl;

	return 0;
}