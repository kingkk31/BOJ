#include <iostream>
#include <string>
using namespace std;
int N;

bool check(string str1,string str2)
{
	if(N%2 == 0)
	{
		for(int i=0;i<str1.length();i++)
		{
			if(str1[i] != str2[i])
				return false;
		}
	}
	else
	{
		for(int i=0;i<str1.length();i++)
		{
			if(str1[i] == str2[i])
				return false;
		}
	}

	return true;
}

int main(void)
{
    cin >> N;

	string str1,str2;
	cin >> str1;
	cin >> str2;

	if(check(str1,str2))
		cout<<"Deletion succeeded"<<endl;
	else
		cout<<"Deletion failed"<<endl;
 
    return 0;
}
