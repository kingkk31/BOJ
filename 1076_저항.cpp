#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
 
int main(void) 
{
	string num;

	long long total= 0; 

	for(int i=2;i>=1;i--)
	{
		cin>>num;
		
		long long what;

		if(num == "black")
			what = 0;
		else if(num == "brown")
			what = 1;
		else if(num == "red")
			what = 2;
		else if(num == "orange")
			what = 3;
		else if(num == "yellow")
			what = 4;
		else if(num == "green")
			what = 5;
		else if(num == "blue")
			what = 6;
		else if(num == "violet")
			what = 7;
		else if(num == "grey")
			what = 8;
		else if(num == "white")
			what = 9;

		total += (pow((double)10,i-1))*what;
	}

	cin>>num;
	long long what;

	if(num == "black")
		what = 1;
	else if(num == "brown")
		what = 10;
	else if(num == "red")
		what = 100;
	else if(num == "orange")
		what = 1000;
	else if(num == "yellow")
		what = 10000;
	else if(num == "green")
		what = 100000;
	else if(num == "blue")
		what = 1000000;
	else if(num == "violet")
		what = 10000000;
	else if(num == "grey")
		what = 100000000;
	else if(num == "white")
		what = 1000000000;

	total *= what;

	cout<<total<<endl;

	return 0;
}
