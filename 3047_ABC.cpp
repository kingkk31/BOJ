#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int a,b,c;

	string str;

	cin>>a>>b>>c;
	cin>>str;

	int A,B,C;
	if(a<b)
	{
		if(c<b)
		{
			A=(a<c)?a:c;
			B=(a>c)?a:c;
			C=b;
		}
		else
		{
			A=a;
			B=b;
			C=c;
		}
	}
	else
	{
		if(c<a)
		{
			A=(b<c)?b:c;
			B=(b>c)?b:c;
			C=a;
		}
		else
		{
			A=b;
			B=a;
			C=c;
		}
	}

	if(str.at(0)=='A')
	{
		if((str.at(1)=='B')&&(str.at(2))=='C')
			cout<<A<<" "<<B<<" "<<C<<endl;
		else
			cout<<A<<" "<<C<<" "<<B<<endl;
	}
	else if(str.at(0)=='B')
	{
		if((str.at(1)=='A')&&(str.at(2))=='C')
			cout<<B<<" "<<A<<" "<<C<<endl;
		else
			cout<<B<<" "<<C<<" "<<A<<endl;
	}
	else
	{
		if((str.at(1)=='A')&&(str.at(2))=='B')
			cout<<C<<" "<<A<<" "<<B<<endl;
		else
			cout<<C<<" "<<B<<" "<<A<<endl;
	}

}