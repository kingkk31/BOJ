#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	int cnt=0;

	for (int A = 1; pow((double)A, 2) <= pow(500.0, 2); A++)
	{
		for (int B = 1; B <= A; B++)
		{
			if (pow((double)A, 2) == pow((double)B, 2) + N)
				cnt++;
		}
	}

	cout << cnt << endl;
	
	return 0;
}