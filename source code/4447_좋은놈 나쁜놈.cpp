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
	int n;
	cin >> n;
	char c = getchar();

	while (n--)
	{
		int g = 0, b = 0;
		string str;
		getline(cin, str);

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'g' || str[i] == 'G')
				g++;
			else if (str[i] == 'b' || str[i] == 'B')
				b++;
		}

		if (g > b)
			cout << str << " is GOOD" << endl;
		else if (g < b)
			cout << str << " is A BADDY" << endl;
		else
			cout << str << " is NEUTRAL" << endl;
	}

	return 0;
}