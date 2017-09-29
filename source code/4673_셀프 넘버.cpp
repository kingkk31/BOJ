#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int check[10001];

void solve(int n)
{
    int num = n, newNum = n;
    while(num != 0)
    {
        newNum += num % 10;
        num /= 10;
    }
    
    if(newNum > 10000 || check[newNum] == 1)
        return;
    
    check[newNum] = 1;
    solve(newNum);
}

int main(void)
{
    memset(check, -1, sizeof(check));
    for(int i=1;i<=10000;i++)
        if(check[i] == -1)
            solve(i);
    
    for(int i=1;i<=10000;i++)
        if(check[i] == -1)
            cout<<i<<endl;
}