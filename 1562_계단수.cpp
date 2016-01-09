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
 
int n;
int cnt = 0;
int cache[1<<10][10][101];
 
int solve(int nums, int len, int pre)
{
    if (len == n)
        return nums == (1<<10)-1;
     
    int &ret = cache[nums][pre][len];
 
    if (ret != -1)
        return ret % 1000000000;
 
    ret = 0;
 
    if (pre > 0)
        ret = (ret + solve(nums | 1 << (pre - 1), len + 1, pre - 1)) % 1000000000;
 
    if (pre < 9)
        ret = (ret + solve(nums | 1 << (pre + 1), len + 1, pre + 1)) % 1000000000;
 
    return ret % 1000000000;
}
 
int main(void)
{
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
 
    if (n < 10)
        printf("0\n");
    else
    {
        for (int i = 1; i < 10; i++)
            cnt = (cnt+solve(1<<i, 1, i))%1000000000;
                 
        printf("%d\n", cnt%1000000000);
    }
 
    return 0;
}