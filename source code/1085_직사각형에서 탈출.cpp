#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int x,y,w,h;
	cin >> x >> y >> w >> h;

	int arr[4] = {x,y,h-y,w-x};

	sort(arr + 0, arr + 4);

	cout << arr[0] << endl;
	
	return 0;
}