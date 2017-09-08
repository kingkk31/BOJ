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
#include <cctype>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	int arr[26] = { 0 };
	int temp[26];
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		arr[(int)(str[i] - 'A')]++;
	int words = 0, cnt = 0, len = str.length();
	
	for (int i = 0; i < n - 1; i++)
	{
		cin >> str;
		cnt = 0;
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < str.length(); i++)
			temp[(int)(str[i] - 'A')]++;
	
		for (int i = 0; i < 26; i++)
			cnt += abs(arr[i] - temp[i]);
		if ((str.length() == len && cnt <= 2) || (str.length() != len && cnt <= 1))
			words++;
	}
	cout << words << endl;

	return 0;
}