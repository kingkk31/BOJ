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
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;
 
int t;
int vt[10001][2];
int score[10001];
 
int solve(int n, int cnt)
{
    if (n >= t)
        return 0;
 
    int &ret = vt[n][cnt];
 
    if (ret != -1)
        return ret;
 
    ret = 0;
 
    if (cnt == 1)
    {
        ret = max(ret, solve(n + 2, 0) + score[n]);
        ret = max(ret, solve(n + 3, 0) + score[n]);
    }
    else
    {
        ret = max(ret, solve(n + 1, cnt + 1) + score[n]);
        ret = max(ret, solve(n + 2, 0) + score[n]);
        ret = max(ret, solve(n + 3, 0) + score[n]);
    }
 
    return ret;
}
 
int main(void)
{
    cin >> t;
 
    memset(vt, -1, sizeof(vt));
 
    for (int i = 0; i < t; i++)
        cin >> score[i];
 
    cout << max(solve(0, 0), solve(1, 0)) << endl;
     
    return 0;
}