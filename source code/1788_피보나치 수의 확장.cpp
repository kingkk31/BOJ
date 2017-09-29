#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    int a = 0, b = 1, c;
    
    if(n > 1)
    {
        for(int i=2;i<=n;i++)
        {
            c = (a + b) % 1000000000;
            if(i == n)
            {
            	if(c > 0)
            		cout<<1<<endl;
            	else if(c == 0)
            		cout<<0<<endl;
            	else
            		cout<<-1<<endl;
            	cout<<abs(c)<<endl;
            }
            a = b % 1000000000;
            b = c % 1000000000;
        }
    }
    else if(n == 1)
    {
    	cout<<1<<endl;
    	cout<<1<<endl;
    }
    else if(n == 0)
    {
    	cout<<0<<endl;
    	cout<<0<<endl;
    }
    else
    {
        for(int i=-1;i>=n;i--)
        {
            c = (b - a) % 1000000000;
            if(i == n)
            {
            	if(c > 0)
            		cout<<1<<endl;
            	else if(c == 0)
            		cout<<0<<endl;
            	else
            		cout<<-1<<endl;
            	cout<<abs(c)<<endl;
            }
            b = a % 1000000000;
            a = c % 1000000000;
        }
    }
    
   return 0;
}

