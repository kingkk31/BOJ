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
#include <iterator>
#include <sstream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int main(void)
{
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	printf("%d\n", ((v-a)/(a-b)) + (((v - a) % (a - b)) == 0 ? 0 : 1) + 1);
	
	return 0;
}