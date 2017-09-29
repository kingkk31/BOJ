#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;
 
void solve(int n)
{
    unsigned long long len = 1, num = 1;
     
    while (1)
    {
        if (num % n == 0)
            break;
         
        num = (num * 10) % n + 1;
 
        len++;
    }
 
    cout << len << endl;
}
 
int main(void)
{
    int n;
 
    while (~scanf("%d", &n))
        solve(n);
     
    return 0;
}