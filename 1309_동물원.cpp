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
	int n;
	int i = 1, j = 1;
	
	for (scanf("%d", &n); n--;)
	{
		i = i * 2 + j;
		j = (i - j) / 2;
		
		if (i >= 9901)
			i %= 9901;
	
	}
	
	printf("%d\n", i);

	return 0;
}
