#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{	
	void *p = malloc(4); 
	puts(((int)p / 10 % 2 ? "Yonsei" : "Korea"));
	
	return 0;
}
