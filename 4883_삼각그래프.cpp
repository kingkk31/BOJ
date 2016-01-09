#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
 
int n;
vector<vector<int> > vt;
int cache[100001][3];
const int INF = 987654321;
 
int dynamic(int row, int col)
{
    if (row == n - 1)
    {
        if (col == 0)
            return vt[row][0] + vt[row][1];
        else if (col == 1)
            return vt[row][1];
        else
            return INF;
    }
 
    int &ret = cache[row][col];
 
    if (ret != -1)
        return ret;
 
    ret = 0;
 
    if (col == 0)
        ret = min(dynamic(row, col+1), min(dynamic(row + 1, col), dynamic(row + 1, col+1))) + vt[row][col];
    else if (col == 1)
    {
        int num1 = min(dynamic(row, col + 1), dynamic(row+1, col));
        int num2 = min(dynamic(row+1, col - 1), dynamic(row + 1, col+1));
 
        ret = min(num1, num2) + vt[row][col];
    }
    else
        ret = min(dynamic(row+1, col - 1), dynamic(row + 1, col)) + vt[row][col];
     
    return ret;
}
 
int main(void)
{
    int cnt = 0;
    while (1)
    {
        cin >> n;
 
        if (n == 0)
            break;
 
        vt = vector<vector<int> >(n, vector<int>(3));
        memset(cache, -1, sizeof(cache));
 
        for (int i = 0; i < n; i++)
            cin >> vt[i][0] >> vt[i][1] >> vt[i][2];
 
        cout << ++cnt<<". "<<dynamic(0, 1) << endl;
    }
     
    return 0;
}
