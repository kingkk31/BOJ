#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int M, D;
	cin>>D>>M;
	
	string str2[7] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday","Monday", "Tuesday"};
	int num[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	for(int i=0;i<(M-1);i++)
	{
		D = D + num[i];
	}
	
	cout<<str2[(D%7)]<<endl;
	
	return 0;
}