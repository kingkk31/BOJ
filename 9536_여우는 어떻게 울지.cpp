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

int main(void)
{
	int t;
	cin >> t;

	for (int a = 0; a < t; a++)
	{
		string str;
		list<string> vt;

		while (str != "\n")
		{
			cin >> str;
			vt.push_back(str);
			str = getchar();
		}

		while (1)
		{
			string str, noi="";
			getline(cin, str);

			if (str == "what does the fox say?")
				break;

			int check = str.find("goes ");
			check += 5;

			while (check != str.size())
				noi += str[check++];
			
			vt.remove(noi);
		}

		list<string>::iterator itr = vt.begin();

		while (itr != vt.end())
		{
			if (itr == --vt.end())
				cout << *(itr++) << endl;
			else
				cout << *(itr++) << " ";
		}
	}

	return 0;
}