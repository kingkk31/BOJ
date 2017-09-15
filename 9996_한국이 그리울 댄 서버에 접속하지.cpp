#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
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
	int n;
	cin >> n;

	string str;
	cin >> str;

	int star;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '*')
			star = i;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		
		bool check = false;

		int pos = 0;
		int ch = 0;

		while (str[pos] != '*')
		{
			if (str[pos] != word[ch])
			{
				check = true;
				break;
			}

			pos++;
			ch++;
		}

		int temp = ch;

		pos = str.length()-1;
		ch = word.length()-1;

		while (str[pos] != '*')
		{
			if (str[pos] != word[ch] || ch < temp)
			{
				check = true;
				break;
			}

			pos--;
			ch--;
		}

		if (check)
			cout << "NE" << endl;
		else
			cout << "DA" << endl;
	}

	return 0;
}
