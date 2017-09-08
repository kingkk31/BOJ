#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int k, n;
		cin >> k;
		cin >> n;
				
		vector<vector<int> > vt;
		
		for (int i = 0; i < k+1; i++)
		{
			vector<int> in;
			in.resize(n);
			vt.push_back(in);			
		}

		for (int i = 0; i < n; i++)
		{
			vt[0][i] = i + 1;
		}

		for (int i = 1; i < k+1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int a = 0;
				while (a != j+1)
				{
					vt[i][j] += vt[i - 1][a];
					a++;
				}
			}
		}

		cout << vt[k][n - 1] << endl;
	}
	
	return 0;
}