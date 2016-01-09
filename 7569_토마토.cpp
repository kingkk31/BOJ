#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int M, N, H;
 
struct XYZ {
    int x, y, z;
};
 
XYZ make(int m, int n, int h)
{
    XYZ box;
    box.x = m;
    box.y = n;
    box.z = h;
 
    return box;
}
 
bool isRange(int y, int x, int z)
{
    if (0 <= y && y < N && 0 <= x && x < M && 0 <= z && z < H)
        return true;
    return false;
}
 
int days(vector<vector<vector<int> > > vt)
{
    int day = 1;
 
    for (int i = 0; i<H; i++)
    {
        for (int k = 0; k < N;k++)
        {
            for (int j = 0; j < M; j++)
            {
                if (vt[i][k][j] == 0)
                    return -1;
                else if (day < vt[i][k][j])
                    day = vt[i][k][j];
            }
        }
    }
 
    return day - 1;
}
 
int main()
{
    cin >> M >> N >> H;
 
    vector<vector<vector<int> > > vt(H,vector<vector<int> >(N, vector<int>(M)));
    queue<XYZ> qu;
     
    for (int i = 0; i<H; i++)
    {
        for (int k = 0; k < N; k++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> vt[i][k][j];
 
                if (vt[i][k][j] == 1)
                    qu.push(make(j,k,i));
            }
        }
    }
     
    while (!qu.empty())
    {
        int a = qu.front().x;
        int b = qu.front().y;
        int c = qu.front().z;
        qu.pop();
 
        for (int i = 0; i<6; i++)
        {
            int nextZ = c + dz[i];
            int nextY = b + dy[i];
            int nextX = a + dx[i];
 
            if (isRange(nextY, nextX, nextZ) && vt[nextZ][nextY][nextX] == 0) 
            {
                qu.push(make(nextX, nextY, nextZ));
                vt[nextZ][nextY][nextX] = vt[c][b][a]+1;
            }
        }
    }
 
    cout << days(vt) << endl;
 
    return 0;
}