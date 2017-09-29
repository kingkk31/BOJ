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
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d\n", min(abs((a + d) - (b + c)), min(abs((a + b) - (c + d)), abs((a + c) - (b + d)))));

	return 0;
}