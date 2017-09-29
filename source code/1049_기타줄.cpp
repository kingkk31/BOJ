#include <iostream>
using namespace std;

int main(void)
{
	int N,M;

	cin>>N>>M;
	
	int P[50];
	int C[50];
		
	int i=0;
	
	while(i<M)
	{
		cin>>P[i], cin>>C[i];
		i++;
	}	

	
	int a, c, temp1 = 0;
	for(a=1;a<M;a++)
	{
		for(c=0;c<(M-1);c++)
		{
			if(P[c]>P[c+1])
			{
				temp1=P[c];
				P[c]=P[c+1];
				P[c+1]=temp1;
			}
		}
	}
	
	
	int b, d, temp2;
	for(b=1;b<M;b++)
	{
		for(d=0;d<(M-1);d++)
		{
			if(C[d]>C[d+1])
			{
				temp2=C[d];
				C[d]=C[d+1];
				C[d+1]=temp2;
			}
		}
	}
	
	int price[3];
	price[0]=(P[0]*(N/6))+(C[0]*(N%6));
	price[1]=C[0]*N;
	price[2]=(P[0]*(N/6))+P[0];

	int e, f, g=0;
	for(e=1;e<3;e++)
	{
		for(f=0;f<2;f++)
		{
			if(price[f]>price[f+1])
			{
				g=price[f];
				price[f]=price[f+1];
				price[f+1]=g;
			}
		}
	}
	
	cout<<price[0]<<endl;

	return 0;
}