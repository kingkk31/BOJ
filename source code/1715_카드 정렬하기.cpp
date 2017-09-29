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
	multiset<int> st;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int num;
		scanf("%d", &num);
		st.insert(num);
	}

	int sum = 0;
	while (st.size() != 1)
	{
		int num1, num2;
		num1 = *(st.begin());
		st.erase(st.begin());
		num2 = *(st.begin());
		st.erase(st.begin());

		sum += (num1 + num2);
		st.insert(num1 + num2);
	}
	cout << sum << endl;

	return 0;
}