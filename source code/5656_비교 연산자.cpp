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
	int k = 1;
	
	while(true)
	{
		int a, b;
		string str;
		cin >> a >> str >> b;

		if (str == "E")
			return 0;
		else 
		{
			cout << "Case " << k << ": ";
			if (str == ">")
				if (a > b)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			else if (str == ">=")
				if (a >= b)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			else if (str == "<")
				if (a < b)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			else if (str == "<=")
				if (a <= b)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			else if (str == "==")
				if (a == b)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			else if (str == "!=")
				if (a != b)
					cout << "true" << endl;
				else
					cout << "false" << endl;
		}
		k++;
	}

	return 0;
}