#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n;	cin >> n; if (90 <= n && n <= 100) cout << "A" << endl; else if (80 <= n && n <= 89) cout << "B" << endl; else if (70 <= n && n <= 79) cout << "C" << endl; else if (60 <= n && n <= 69) cout << "D" << endl; else cout << "F" << endl;	return 0;
}