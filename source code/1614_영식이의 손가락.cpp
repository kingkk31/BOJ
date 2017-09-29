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

int main(void)
{
	unsigned long long hurt, cnt;
	scanf("%llu %llu", &hurt, &cnt);

	if (hurt == 1 && cnt == 0)
		printf("0\n");
	else 
	{
		unsigned long long num = 0;
		
		if (hurt == 1)
			num = cnt * 8;
		else if (hurt == 5)
			num = cnt * 8 + 4;
		else
		{
			if (cnt % 2 == 0)
			{
				num += cnt * 4;
				num += hurt - 1;
			}
			else
			{
				num += cnt * 4;
				num += 5 - hurt;
			}
		}
		printf("%llu\n", num);
	}
	
	return 0;
}