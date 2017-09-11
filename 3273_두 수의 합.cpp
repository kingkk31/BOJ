#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);

	vector<int> vt(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	int x, cnt = 0;
	scanf("%d", &x);

	sort(vt.begin(), vt.end());

	for (int i = 0; i < vt.size(); i++){
		int temp = x - vt[i];
		if (binary_search(vt.begin(), vt.end(), temp))
			cnt++;
	}
	printf("%d\n", cnt/2);
	return 0;
}