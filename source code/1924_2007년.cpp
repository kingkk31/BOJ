#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int month, date;
	cin>>month>>date;
	
	string str[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int num[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	for(int i=0;i<(month-1);i++)
	{
		date = date + num[i];
	}
	
	cout<<str[(date%7)]<<endl;


	return 0;
}