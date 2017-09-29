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
	getline(cin, str);

	int i = 0;
	while (i < str.length())
	{
		switch (str[i])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': printf("%c", str[i]); i += 3; break;
		default: printf("%c", str[i]); i++; break;
		}		
	}

	return 0;
}