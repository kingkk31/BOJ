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

unsigned long long binary_to_decimal(string binary_num)
{
	unsigned long long num = 0;
	reverse(binary_num.begin(), binary_num.end());

	for (int i = 0; i < binary_num.length(); i++)
		num += ((unsigned long long)(binary_num[i] - '0')) * (unsigned long long)pow(2, i);

	return num;
}

string decimal_to_binary(unsigned long long decimal_num, int len)
{
	string num = "";
	while (num.length() != len) //길이 포멧에 따라
	{
		num += ((char)(decimal_num % 2) + '0');
		decimal_num /= 2;
	}

	return num;
}

void case1(string str)
{
	string binary_string = "";
	reverse(str.begin(), str.end());

	unsigned long long temp = 0;
	int degree = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '.')
			temp += ((unsigned long long)(str[i] - '0')) * (unsigned long long)pow(10, degree++);
		else
		{
			string sub = decimal_to_binary(temp, 8);
			binary_string += sub;
			temp = degree = 0;
		}
	}
	string sub = decimal_to_binary(temp, 8);
	binary_string += sub;

	reverse(binary_string.begin(), binary_string.end());
	//여기까지가 전체를 하나의 이진수로 바꾼 것

	cout << binary_to_decimal(binary_string); //이진수를 십진수로
}

void case2(string str)
{
	unsigned long long decimal_num = 0;
	reverse(str.begin(), str.end());

	for (int i = 0; i < str.length(); i++)
		decimal_num += ((unsigned long long)(str[i] - '0')) * (unsigned long long)pow(10, i);
	//십진수로 문자열 처리

	string binary_string = decimal_to_binary(decimal_num, 64);
	reverse(binary_string.begin(), binary_string.end());
	//전체를 이진수로

	for (int i = 0; i < binary_string.length(); i += 8)
	{
		printf("%llu", binary_to_decimal(binary_string.substr(i, 8)));
		if (i != 56)
			printf(".");
	}
	//8개씩 끊어서 십진수로
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m;
		string str;
		cin >> m >> str;

		if (m == 1)
			case1(str);
		else
			case2(str);
		cout << endl;
	}

	return 0;
}