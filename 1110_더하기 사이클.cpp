#include <iostream>
using namespace std;
 
int main(void)
{
    int num;
	cin>>num;

	int ten = num/10;
	int one = num%10;

	int cnt=1;
	
	int a[2] = {ten,one};

	int temp = (a[0]*10)+a[1];
	
	int tmp = a[0];
	a[0] = a[1];
	a[1] = (tmp+a[1])%10;
		
	while(1)
	{
		int temp = (a[0]*10)+a[1];
		if(temp == num)
			break;

		int tmp = a[0];
		a[0] = a[1];
		a[1] = (tmp+a[1])%10;

		cnt++;
	}

	cout<<cnt<<endl;
	
    return 0;
}