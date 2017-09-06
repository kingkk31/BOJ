#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int cnt = 0;

		int sx, sy, fx, fy;
		cin >> sx >> sy >> fx >> fy;

		int n;
		cin >> n;

		for (int j = 0; j < n; j++)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;
						
			int len = (sx - fx)*(sx - fx) + (sy - fy)*(sy - fy);
			int d1 = (sx - cx)*(sx - cx) + (sy - cy)*(sy - cy);
			int d2 = (fx - cx)*(fx - cx) + (fy - cy)*(fy - cy);


			if ((d1 < r*r && d2 > r*r) || (d2 < r*r && d1 > r*r))
				cnt++;
			
		}

		cout << cnt << endl;

	}

	return 0;
}