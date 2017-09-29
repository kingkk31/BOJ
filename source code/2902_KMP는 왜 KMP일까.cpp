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
	string str, result = "";
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		if ('A' <= str[i] && str[i] <= 'Z')
			cout<<str[i]<<"";
	cout << endl;

	return 0;
}