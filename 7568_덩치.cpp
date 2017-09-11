#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<vector<int> > vt;
	vector<int> count;

	for (int i = 0; i < n; i++)
	{
		vector<int> in;
		in.resize(2);
		vt.push_back(in);
	}

	for (int i = 0; i < n; i++)
	{
		count.push_back(1);
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> vt[i][0] >> vt[i][1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vt[i][0] < vt[j][0] && vt[i][1] < vt[j][1])
				count[i]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			cout << count[i] << " ";
		else
			cout << count[i] << endl;
	}
	
	return 0;
}