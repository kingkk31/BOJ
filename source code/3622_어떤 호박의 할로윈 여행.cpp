#include <iostream>
using namespace std;

int main(void)
{	
    int A,a,B,b,P;
	cin>>A>>a>>B>>b>>P;

	if(P < A || P < B)
		cout<<"No"<<endl;
	else
	{
		if(P >= A+B) 
			cout<<"Yes"<<endl;
		else if(P >= A && A > B && a >= B)
			cout<<"Yes"<<endl;
		else if(P >= B && B > A && b >= A)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	
	return 0;
}