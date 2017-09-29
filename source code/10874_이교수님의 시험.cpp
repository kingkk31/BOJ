#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++)
    {
        int cnt = 0;
        for(int j=1;j<=10;j++)
        {
            int ans;
            scanf("%d", &ans);
            if(ans == ((j-1)%5)+1)
                cnt++;
        }
        
        if(cnt == 10)
            cout<<i<<endl;
    }
}