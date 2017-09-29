#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;
 
void dot(int a, int &x, int &y)
{
    while (a > 1 + ((y*(y - 1)) / 2))
        y++;
 
    if (a < 1 + ((y*(y - 1)) / 2))
        y--;
 
    int temp = 1 + (y*(y - 1) / 2);
 
    while (a != temp)
    {
        temp++;
        y--;
        x++;
    }
}
 
int main(void)
{
    int t;
    scanf("%d", &t);
     
    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
 
        int x1 = 1, y1 = 1;
        int x2 = 1, y2 = 1;
        dot(a, x1, y1);
        dot(b, x2, y2);
         
        int x3 = x1 + x2, y3 = y1 + y2;
     
        if (x3 == 1)
            printf("%d\n", 1 + ((y3*(y3 - 1)) / 2));
        else
        {
            int q = y3 + (x3 - 1);
            int num = 1 + ((q * (q-1)) / 2);
            num += x3 - 1;
            printf("%d\n", num);
        }
    }
     
    return 0;
}