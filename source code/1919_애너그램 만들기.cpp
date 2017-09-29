#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int arr1[26]={0};
int arr2[26]={0};

int main(void)//97~122
{
	string str1,str2;
	cin>>str1>>str2;

	for(int i=0;i<str1.length();i++)
	{
		arr1[(int)str1[i]-'a']++;
	}

	for(int i=0;i<str2.length();i++)
	{
		arr2[(int)str2[i]-'a']++;
	}
	
	int num=0;

	for(int i=0;i<26;i++)
	{
		num += abs(arr2[i]-arr1[i]);
	}

	cout<<num<<endl;
		
	return 0;
}