#include <iostream>
#include <math.h>

using namespace std;

int cache[1000001];

void init(int cache[])
{
	for (int i = 0; i < 1000001; i++)
		cache[i] = -1;
}

int check(int n)
{
	if (n <= 0)
		return 1;

	int &ret = cache[n];

	if (ret != -1)
		return ret;

	return ret = (check(n - sqrt((double)n)) + check(log((double)n)) + check(n*sin((double)n)*sin((double)n)))%1000000;
}

int main()
{
	init(cache);

	while (true){
		int n;
		cin >> n;
		if (n == -1)
			break;

		cout << check(n) << endl;
	}

	return 0;
}