#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string str;
	for (int i = 1; i <= n; i++)
		str += to_string(i);

	cout<<str.find(to_string(n))+1;
}
