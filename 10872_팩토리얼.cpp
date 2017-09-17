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

vector<int> operator*(vector<int> vt1, vector<int> vt2) //큰 수 곱셈 operator*
{
	vector<int> vt3(vt1.size()+vt2.size(), 0);

	for (int i = 0; i < vt1.size(); i++)
		for (int j = 0; j < vt2.size(); j++)
		{
			vt3[i + j] += vt1[i] * vt2[j];
			if (vt3[i + j] >= 10)
			{
				vt3[i + j + 1] += vt3[i + j] / 10;
				vt3[i + j] %= 10;
			}
		}

	return vt3;
}

int main(void)
{
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	vector<int> multiplicand(1, 1); //피승수, 곱해지는 값
	
	for (int i = 2; i <= n; i++) //펙토리얼 계산, 하나씩 곱한다
	{
		int num = i;
		vector<int> multiplier; //승수, 피승수에 곱하는 값
		while (num != 0)
		{
			multiplier.push_back(num % 10);
			num /= 10;
		}
		//피승수 세팅

		multiplicand = multiplicand * multiplier;
	}
	
	reverse(multiplicand.begin(), multiplicand.end()); //계산결과는 뒤집혀 있음

	int start = 0;
	while (1)
	{
		if (multiplicand[start] != 0)
			break;
		start++;
	}
	//오버플로우로 나오는 0들은 continue;

	for (int i = start; i < multiplicand.size(); i++)
		cout << multiplicand[i];
	cout << endl;

	return 0;
}