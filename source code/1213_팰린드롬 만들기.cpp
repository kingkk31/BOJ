#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stdio.h>
#define MAX 1000001
using namespace std;

vector<int> apb;

int checker()
{
	bool chk = false;

	int posit = -1;

	for (int i = 0; i < 26; i++)
		if (apb[i] % 2 == 1){
			if (chk)
				return -2;
			else
				chk = true;

			posit = i;
		}

	return posit;
}

int main() 
{
	apb.assign(26, 0);

	while (true){
		char c = getchar();
		if (c == '\n') break;

		apb[c - 'A']++;
	}

	int posit = checker();

	if (posit == -2){
		cout << "I'm Sorry Hansoo";

		return 0;
	}

	string str = "";

	if (posit != -1){
		str = posit+'A';
		apb[posit] -= 1;
	}

	for (int i = 25; i >= 0; i--)
	{
		while (apb[i] != 0)
		{
			str = (char)(i+'A') + str + (char)(i+'A');
			apb[i] -= 2;
		}
	}

	cout << str;

	return 0;
}