#include <iostream>
using namespace std;

int main(void)
{  
	int arr[5]={0};

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			int score;
			cin>>score;

			arr[i] += score;
		}
	}

	int max=0;
	int num=0;

	for(int i=0;i<5;i++)
	{
		if(max<arr[i])
		{
			num = i;
			max = arr[i];
		}
	}

	cout<<num+1<<" "<<arr[num]<<endl;

	return 0;
}