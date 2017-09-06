#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

char people[51][51];
int n;

int check(int person)
{
	set<int> st;
	for (int i = 0; i < n; i++)
	{
		if (people[person][i] == 'Y')
		{
			st.insert(i);
		
			for (int j = 0; j < n; j++)
			{
				if (j == person || people[person][j] == 'Y')
					continue;

				if (people[i][j] == 'Y')
					st.insert(j);
			}
		}
	}

	return st.size();
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < n; j++)
			people[i][j] = str[j];
	}

	vector<int> num;

	for (int i = 0; i < n; i++)
		num.push_back(check(i));
	
	sort(num.begin(), num.end());
	cout << num[num.size() - 1] << endl;
	
	return 0;
}
