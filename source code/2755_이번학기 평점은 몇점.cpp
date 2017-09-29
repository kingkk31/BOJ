#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(void)
{	
	map<string,double> m;
	m["A+"] = 4.3; 
	m["A0"] = 4.0; 
	m["A-"] = 3.7;
    m["B+"] = 3.3; 
	m["B0"] = 3.0; 
	m["B-"] = 2.7;
    m["C+"] = 2.3; 
	m["C0"] = 2.0; 
	m["C-"] = 1.7;
    m["D+"] = 1.3; 
	m["D0"] = 1.0; 
	m["D-"] = 0.7;
    m["F"] = 0.0;

	double total=0,many=0;
	int T;
	cin>>T;

	for(int i=0;i<T;i++)
	{
		string str1,str2;
		double point;

		cin>>str1>>point>>str2;

		total += (point * m[str2]);
		many += point;
	}

	printf("%.2lf\n", total/many+0.001);
	
    return 0;
}