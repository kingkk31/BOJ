#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		bool is[26] = { 0 };
		char al[27];
		for (int a = 0; a < 26; a++)
		{
			al[a] = 'A'+a;
		}

		string str;
		cin >> str;
		int total = 0;

		for (int j = 0; j < str.length(); j++)
		{
			for (int k = 0; k < 26; k++)
			{
				if (str[j] == al[k])
					is[k] = 1;
			}
		}

		for (int b = 0; b < 26; b++)
		{
			if (!is[b])
				total += 65 + b;
		}

		cout << total<<endl;

	}

	
	return 0;
}

