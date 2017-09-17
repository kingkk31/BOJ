#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int main(void) 
{
	int N;
	cin >> N;

	int total = 0;

	for (int i = 0; i < N; i++)
	{
		int people, apple;
		cin >> people >> apple;

		if (people > apple)
		{
			total += apple;
			continue;
		}

		int cnt = 1;
		while (people*cnt < apple)
			cnt++;

		if (people*cnt > apple)
			cnt--;
			
		total += apple - (people*cnt);
	}

	cout << total << endl;

	return 0;
}
