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
	string str;
	while (getline(cin, str))
	{
		int small = 0, big = 0, digit = 0, space = 0;
		for (int i = 0; i < str.length(); i++)
			if (str[i] == ' ')
				space++;
			else if ('a' <= str[i] && str[i] <= 'z')
				small++;
			else if ('A' <= str[i] && str[i] <= 'Z')
				big++;
			else
				digit++;
		cout << small << " " << big << " " << digit << " " << space << endl;
	}
	
	return 0;
}