#include <iostream>
using namespace std;


int main(void)
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}