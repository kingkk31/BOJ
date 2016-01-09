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
 
unsigned long long cache[1000001][2];
int N;
 
unsigned long long solve(int num, int len)
{
    if (len == N)
        return 1;
 
    unsigned long long &ret = cache[len][num];
 
    if (ret != -1)
        return ret;
 
    if (len == N - 1)
        return ret = (solve(1, len + 1)) % 15746;
    else
        return ret = ((solve(1, len + 1)% 15746) + (solve(0, len + 2)% 15746));
 
    return ret % 15746;
}
 
int main(void)
{
    cin >> N;
 
    memset(cache, -1, sizeof(cache));
 
    cout << solve(0, 0) % 15746 << endl;
 
    return 0;
}