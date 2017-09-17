#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        
        while(a != b)
        {
            if(a > b)
                a /= 2;
            else if(a < b)
                b /= 2;
        }
        printf("%d\n", a*10);
    }
}