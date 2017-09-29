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
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		printf("%c", str[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}

	return 0;
}