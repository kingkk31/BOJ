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
	int t;
	scanf("%d", &t);
	while(t--) 
	{
		int x, y;
		scanf("%d %d", &x, &y);

		long long cnt = 0, diff = y - x;
		for (long long i = 1; i < 50000; i++)
		{
			if (diff < i * i)
			{
				long long maxi = i - 1;
				diff -= (maxi * maxi);
				cnt += 2 * maxi - 1;
				
				while (diff != 0)
				{
					long long next = diff / maxi;
					cnt += next;
					diff -=  next * maxi;
					maxi--;
				}

				break;
			}
		}
		
		cout << cnt << endl;
	}
}