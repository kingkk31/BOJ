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

typedef struct student {
	char name[11];
	int korea, english, math;
}student;

bool comp1(student left, student right)
{
	return left.korea > right.korea;
}

bool comp2(student left, student right)
{
	return left.english < right.english;
}

bool comp3(student left, student right)
{
	return left.math > right.math;
}

bool comp4(student left, student right)
{
	if (strcmp(left.name, right.name) < 0)
		return true;
	return false;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<student> vt(n);
	for (int i = 0; i < n; i++)
		scanf("%s %d %d %d", vt[i].name, &vt[i].korea, &vt[i].english, &vt[i].math);
	
	stable_sort(vt.begin(), vt.end(), comp4);
	stable_sort(vt.begin(), vt.end(), comp3);
	stable_sort(vt.begin(), vt.end(), comp2);
	stable_sort(vt.begin(), vt.end(), comp1);
	for (int i = 0; i < n; i++)
		printf("%s\n", vt[i].name);

	return 0;
}