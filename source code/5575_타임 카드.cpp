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
#pragma warning(disable:4996)
using namespace std;

void solve(int *arr1, int *arr2)
{
	int hour = 0, minute = 0, second = 0;
	
	//초
	if (arr1[2] < arr2[2])
		second = arr2[2] - arr1[2];
	else if(arr1[2] == arr2[2])
		second = 0;
	else
	{
		arr1[1]++;
		if (arr1[1] >= 60)
		{
			arr1[0]++;
			arr1[1] %= 60;
		}
		second = 60 - arr1[2] + arr2[2];
	}

	//분
	if (arr1[1] < arr2[1])
		minute = arr2[1] - arr1[1];
	else if (arr1[1] == arr2[1])
		minute = 0;
	else
	{
		arr1[0]++;
		minute = 60 - arr1[1] + arr2[1];
	}

	//시
	hour = arr2[0] - arr1[0];

	cout << hour << " " << minute << " " << second << " " << endl;
}

int main(void)
{
	int aArr1[3] = { 0 }, aArr2[3] = { 0 }, bArr1[3] = { 0 }, bArr2[3] = { 0 }, cArr1[3] = { 0 }, cArr2[3] = { 0 };

	cin >> aArr1[0] >> aArr1[1] >> aArr1[2] >> aArr2[0] >> aArr2[1] >> aArr2[2];
	cin >> bArr1[0] >> bArr1[1] >> bArr1[2] >> bArr2[0] >> bArr2[1] >> bArr2[2];
	cin >> cArr1[0] >> cArr1[1] >> cArr1[2] >> cArr2[0] >> cArr2[1] >> cArr2[2];

	solve(aArr1, aArr2);
	solve(bArr1, bArr2);
	solve(cArr1, cArr2);

	return 0;
}