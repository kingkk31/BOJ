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
	int t;
	cin >> t;
	while (t--)
	{
		int yonsei = 0, korea = 0;
		for (int i = 0; i < 9; i++)
		{
			int a, b;
			cin >> a >> b;
			yonsei += a;
			korea += b;
		}

		if (yonsei > korea)
			cout << "Yonsei" << endl;
		else if (yonsei < korea)
			cout << "Korea" << endl;
		else
			cout << "Draw" << endl;
	}

	return 0;
}