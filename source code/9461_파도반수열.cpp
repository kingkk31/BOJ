#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
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
 
int main(void)
{
    vector<long long> vt(101,0);
 
    vt[0] = 0;
    vt[1] = 1;
    vt[2] = 1;
    vt[3] = 1;
 
    for (int i = 4; i <= 100; i++)
        vt[i] = vt[i - 2] + vt[i - 3];
 
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
 
        cout << vt[n] << endl;
    }
     
    return 0;
}