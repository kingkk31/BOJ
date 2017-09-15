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

	
	for (int i = 2; i < primeArray.size(); i++)
		if (primeArray[i])
			prime.push_back(i);
}

int main(void)
{
	eratos(10000);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a = 0, b = 10000;
		for (int i = 0; i < prime.size() && prime[i] < n; i++)
		{
			int num = n - prime[i];
			if(binary_search(prime.begin(), prime.end(), num) && abs(num - prime[i]) < abs(b - a))
				{
					a = prime[i];
					b = num;
				}
		}
		
		if (a > b)
			swap(a, b);
		cout << a << " " << b << endl;
	}

	return 0;
}