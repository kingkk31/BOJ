#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

int main(void)//97~122
{
	int T;
	cin>>T;
	while(getchar() != '\n');
	for(int a=0;a<T;a++)
	{		
		string str1,str2;
		cin>>str1>>str2;

		int arr1[26]={0};
		int arr2[26]={0};

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

		if(num == 0)
			cout<<str1<< " & "<<str2<<" are anagrams."<<endl;
		else
			cout<<str1<< " & "<<str2<<" are NOT anagrams."<<endl;
	}
	return 0;
}
