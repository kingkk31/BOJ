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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	set<int> st;
	
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		st.insert(num % 42);
	}

	cout << st.size() << endl;

	return 0;
}