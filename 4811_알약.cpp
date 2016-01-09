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
 
long long cache[31][2*31];//w,h
int N;
 
long long solve(int w, int h)
{
    if (w <= 0 && h <= 0)
        return 1;
 
    long long &ret = cache[w][h];
 
    if (ret != -1)
        return ret;
 
    ret = 0;
 
    if(w > 0)
        ret += solve(w - 1, h + 1);
     
    if(h > 0)
    ret += solve(w, h - 1);
     
    return ret;
}
 
int main(void)
{
    memset(cache, -1, sizeof(cache));
 
    while (1)
    {
        cin >> N;
 
        if (N == 0)
            break;
 
        cout<<solve(N, 0)<<endl;
    }
 
    return 0;
}