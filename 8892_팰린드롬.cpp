#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
string operator+(string str1, string str2)
{	
	int m=str1.size(),n=str2.size();
	char *p = new char[m+n+10];

	int i,j;
	for(i=0;i<m;i++)
		p[i]=str1[i];

	for(j=i;j<i+n;j++)
		p[j]=str2[j-i];

	p[j]=0;

	string str(p);

	return str;
}

string check(vector<string> vt)
{
	for(int a=0;a<vt.size();a++)
	{
		for(int b=0;b<vt.size();b++)
		{
			if(a==b)
				continue;

			string make = vt[a]+vt[b];

			int siz = make.size()/2;
			int cnt=0;

			for(int i=0;i<siz;i++)
			{
				if(make[i] == make[make.size()-1-i])
					cnt++;
			}

			if(cnt == siz)
				return make;
		}
	}

	return "0";
}

int main(void)
{
    int T;
	cin>>T;

	for(int i=0;i<T;i++)
	{
		int k;
		cin>>k;

		vector<string> vt;

		for(int j=0;j<k;j++)
		{
			string str;
			cin>>str;

			vt.push_back(str);
		}

		cout<<check(vt)<<endl;		
	}
	
    return 0;
}