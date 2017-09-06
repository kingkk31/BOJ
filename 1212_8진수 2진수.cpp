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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

string intToString(int n)
{
	stringstream s;
	s << n;
	return s.str();
}

int main(void)
{
	string str;
	cin >> str;
	
	if (str == "0")
	{
		cout << "0";
		return 0;
	}

	for (int i = 0; i < str.length(); i++)
	{
		string binary = "";
		int num = (int)(str[i] - '0');

		while (num != 0)
		{
			string temp = intToString(num % 2);
			binary = "" + temp + binary;
			num /= 2;
		}

		if (i != 0)
			while (binary.length() != 3)
				binary = "0" + binary;
		
		cout << binary;
	}

	return 0;
}