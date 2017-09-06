#include <iostream>
using namespace std;

int main(void)
{
	long N;
	int F;

	cin>>N;
	cin>>F;

	int A;
	A=N%F;

	if(A==0)
	{
		long N2;
		N2=(N/100)*100;
		
		long D;
		D=N2%F;
		if(D==0)
			cout<<"00"<<endl;
		else
		{
			long E;
			E=N2-D;
			E=E+F;

			int K;
			K=N2-E;
			if(K<0)
				K=K*(-1);
			if(K>=10)
				cout<<K<<endl;
			else
				cout<<0<<K<<endl;}

		
	}
	else
	{
		long N1;
		N1=(N/100)*100;
		
		long B;
		B=N1%F;
		if(B==0)
			cout<<"00"<<endl;
		else
		{
			long C;
			C=N1-B;
			C=C+F;
			int M;
			M=N1-C;
			if(M<0)
				M=M*(-1);
			if(M>=10)
				cout<<M<<endl;
			else
				cout<<0<<M<<endl;
		}
		
	}
	return 0;
}

