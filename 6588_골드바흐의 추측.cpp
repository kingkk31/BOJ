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

vector<int> prime;

void eratos(int n)
{
	if (n <= 1)
		return;

	vector<bool> primeArray(n + 1, true);
	for (int i = 2; (i*i) <= n; i++)
		if (primeArray[i])
			for (int j = i*i; j <= n; j += i)
				primeArray[j] = false;

	for (int i = 3; i < primeArray.size(); i++)
		if (primeArray[i])
			prime.push_back(i);
}

bool binarySearch(int s, int e, int num)
{
	int l = s, r = e, mid;

	while (l <= r)
	{
		mid = (l + r) / 2;
		if (prime[mid] == num)
			return true;
		else if (prime[mid] > num)
			r = mid - 1;
		else
			l = mid + 1;
	}

	return false;
}

int main(void)
{
	eratos(1000000);
	
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;

		bool flag = false;
		for (int i = 0; i < prime.size(); i++)
		{
			int b = prime[i], a = n - prime[i];
			if (a % 2 == 0)
				continue;

			if (binarySearch(i, prime.size() - 1, a))
			{
				if (a > b)
					swap(a, b);
				printf("%d = %d + %d\n", n, a, b);
				flag = true;
				break;
			}
		}

		if (!flag)
			cout << "Goldbach's conjecture is wrong." << endl;
	}
	
	return 0;
}