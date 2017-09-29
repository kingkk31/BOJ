#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, mini = 987654321, sum = 0;
        for(int i=0;i<7;i++)
        {
            scanf("%d", &n);
            if(n % 2 == 0)
            {
                sum += n;
                mini = min(mini, n);
            }
        }
        cout<<sum<<" "<<mini<<endl;
    }
}