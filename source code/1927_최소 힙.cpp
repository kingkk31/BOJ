#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

int main()
{
	multiset<int> mtset;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (mtset.begin() == mtset.end())
				cout << 0 << endl;
			else
			{
				cout << *(mtset.begin()) << endl;
				mtset.erase(mtset.begin());
			}
		}
		else
			mtset.insert(x);
	}

	return 0;
}
