#include <iostream>
using namespace std;

int main(void)
{
	int N;
	cin>>N;

	int *A = new int[N];
	int *B = new int[N];
	
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}

	for(int i=0;i<N;i++)
	{
		cin>>B[i];
	}

	for(int i=0;i<N-1;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(A[i] > A[j])
			{
				int temp;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
			if(B[i] < B[j])
			{
				int temp;
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}

	int num=0;

	for(int i=0;i<N;i++)
	{
		num += A[i]*B[i];
	}

	cout<<num<<endl;

	return 0;
}