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
	cin >> n;
	while (n--)
	{
		int arr[5] = { 0 };
		for (int i = 0; i < 5; i++)
			cin >> arr[i];
		sort(arr + 0, arr + 5);
		if (arr[3] - arr[1] >= 4)
			cout << "KIN" << endl;
		else
			cout << arr[1] + arr[2] + arr[3] << endl;
	}

	return 0;
}