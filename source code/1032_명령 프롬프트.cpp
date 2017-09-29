#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	
	int n;

	cin >> n;

	string* str = new string[n];

	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	int *cnt=new int[str[0].length()];
	for (int a = 0; a < str[0].length(); a++)
	{
		cnt[a] = 0;
	}
		
	for (int k = 0; k < str[0].length(); k++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[0].at(k) == str[j].at(k))
			{
				cnt[k]++;
			}
		}
	}
	

	for (int b = 0; b <str[0].length(); b++)
	{
		if (cnt[b] == n)
		{
			cout << str[0].at(b);
		}
		else
		{
			cout << "?";
		}
		
	}
	
	


	return 0;
}