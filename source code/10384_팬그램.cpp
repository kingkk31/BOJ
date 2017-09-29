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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int main(void)
{
	int t, len, alphabet[26];
	scanf("%d", &t);
	getchar();

	for (int i = 1; i <= t; i++)
	{
		string str;
		getline(cin, str);

		memset(alphabet, 0, sizeof(alphabet));
		len = str.length();
		for (int j = 0; j < len; j++)
		{
			char c = str[j];
			if ('a' <= c && c <= 'z')
			{
				int index = (int)(c - 'a');
				alphabet[index]++;
			}
			else if ('A' <= c && c <= 'Z')
			{
				int index = (int)(c - 'A');
				alphabet[index]++;
			}
			else
				continue;
		}

		printf("Case %d: ", i);
		int cnt = 4;
		for (int j = 0; j < 26; j++)
			cnt = min(cnt, alphabet[j]);
		switch (cnt)
		{
			case 0: printf("Not a pangram\n"); break;
			case 1: printf("Pangram!\n"); break;
			case 2: printf("Double pangram!!\n"); break;
			default: printf("Triple pangram!!!\n"); break;
		}		
	}

	return 0;
}