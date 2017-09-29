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
	int x = 0, y = 0, n;
	cin >> n;

	string str;
	cin >> str;

	set<pair<int, int> > hs;
	hs.insert(make_pair(x, y));

	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'S')
			y--;
		else if (str[i] == 'E')
			x++;
		else if (str[i] == 'N')
			y++;
		else if (str[i] == 'W')
			x--;

		hs.insert(make_pair(x, y));
	}

	cout << hs.size() << endl;
	
	return 0;
}