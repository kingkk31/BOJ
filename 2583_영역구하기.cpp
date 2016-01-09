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
 
int m, n, k;
int dy[4] = {-1,0,0,1};
int dx[4] = { 0,-1,1,0 };
 
bool isRange(int x, int y)
{
    if (0 <= y && y < m && 0 <= x && x < n)
        return true;
    return false;
}
 
void DFS(int y, int x, int &cnt, vector<vector<int> > &vt)
{
    cnt++;
    vt[y][x] = 2;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if (isRange(nx,ny) && vt[ny][nx] == 0)
            DFS(ny, nx, cnt, vt);
    }
}
 
int main(void) //문제는 (x,y)
{
    scanf("%d %d %d", &m, &n, &k);
 
    vector<vector<int> > vt(m, vector<int>(n,0));
    vector<int> siz;
 
    for (int i = 0; i < k; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
 
        for (int j = b; j < d; j++)
            for (int q = a; q < c; q++)
                vt[j][q] = 1;
    }
 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vt[i][j] == 0)
            {
                int count = 0;
                DFS(i, j, count, vt);
                siz.push_back(count);
            }
        }
    }
 
    sort(siz.begin(), siz.end());
    cout << siz.size() << endl;
    for (int i = 0; i < siz.size(); i++)
        cout << siz[i] << " ";
    cout << endl;
     
    return 0;
}