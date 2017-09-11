#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if ((i == 0) || (i == (b - 1)))
				{
					cout << "#";
				}
				else
				{
					if ((j == 0) || (j == (b - 1)))
					{
						cout << "#";
					}
					else
					{
						cout << "J";
					}
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}