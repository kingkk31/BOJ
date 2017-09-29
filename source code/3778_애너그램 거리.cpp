#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

int main(void)
{
	int T;
	cin>>T;
	while(getchar() != '\n');
	for(int a=0;a<T;a++)
	{		
		char str1[50]={0};
		char str2[50]={0};

		fgets(str1,sizeof(str1),stdin);
		fgets(str2,sizeof(str2),stdin);

		int arr1[26]={0};
		int arr2[26]={0};

		for(int i=0;i<sizeof(str1);i++)
		{
			arr1[(int)str1[i]-'a']++;
		}

		for(int i=0;i<sizeof(str2);i++)
		{
			arr2[(int)str2[i]-'a']++;
		}

		int num=0;

		for(int i=0;i<26;i++)
		{
			num += abs(arr2[i]-arr1[i]);
		}

		cout<<"Case #"<<a+1<<": "<<num<<endl;
	}
	return 0;
}