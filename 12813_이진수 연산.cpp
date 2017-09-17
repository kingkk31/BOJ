#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#pragma warning (disable:4996)
using namespace std;

int main(void)
{
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++)
		printf("%d", ((int)(a[i] - '0')) & ((int)(b[i] - '0')));
	printf("\n");

	for (int i = 0; i < a.length(); i++)
		printf("%d", ((int)(a[i] - '0')) | ((int)(b[i] - '0')));
	printf("\n");

	for (int i = 0; i < a.length(); i++)
		printf("%d", ((int)(a[i] - '0')) ^ ((int)(b[i] - '0')));
	printf("\n");

	for (int i = 0; i < a.length(); i++)
	{
		if((int)(a[i] - '0'))
			printf("0");
		else printf("1");
	}
	printf("\n");

	for (int i = 0; i < b.length(); i++)
	{
		if ((int)(b[i] - '0'))
			printf("0");
		else printf("1");
	}
	printf("\n");

	return 0;
}