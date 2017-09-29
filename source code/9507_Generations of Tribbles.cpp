#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

int main(void)
{
	unsigned long long cache[70];

	for(int i=0;i<=67;i++)
	{
		if(i < 2)
			cache[i] = 1;
		else if(i == 2)
			cache[i] = 2;
		else if(i == 3)
			cache[i] = 4;
		else
			cache[i] = cache[i - 1] +cache[i - 2] + cache[i - 3] + cache[i - 4];
	}
	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		printf("%llu\n", cache[n]);
	}
   
   return 0;
}