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
	int n;
	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << "You get "<< a/b << " piece(s) and your dad gets " << a%b << " piece(s)." << endl;
	}

	return 0;
}