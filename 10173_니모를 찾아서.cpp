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
	string str;
	while (true)
	{
		bool ch = false;
		getline(cin, str);

		if (str == "EOI")
			break;

		for (int i = 0; i < str.length() - 3; i++)
		{
			if (str[i] != 'n' && str[i] != 'N')
				continue;
			else
			{
				if ((str[i + 1] == 'e' || str[i + 1] == 'E')
					&& (str[i + 2] == 'm' || str[i + 2] == 'M')
					&& (str[i + 3] == 'o' || str[i + 3] == 'O'))
				{
					ch = true;
					break;
				}
			}
		}

		if (ch)
			cout << "Found" << endl;
		else
			cout << "Missing" << endl;
	}

	return 0;
}