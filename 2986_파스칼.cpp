#include <iostream>
#include <math.h>
using namespace std;
 
int main(void)
{   
    int N;
    cin>>N;
 
    if(N%2 == 0)
        cout<<N-(N/2)<<endl;
    else
    {
        int num=1;
 
        for(int i=3;i<=sqrt((double)N);i+=2)
        {
            if(N%i == 0)
            {
                num = N/i;
                break;
            }
        }
 
        cout<<N-num<<endl;
    }
 
    return 0;
}