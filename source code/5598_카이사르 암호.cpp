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
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case 'A': printf("%c", 'X'); break;
		case 'B': printf("%c", 'Y'); break;
		case 'C': printf("%c", 'Z'); break;
		default: printf("%c", (char)(str[i] - 3)); break;
		}
	}	
	printf("\n");

	return 0;
}