#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int M, N;
 
bool isRange(int y, int x)
{
    if (0 <= y && y < N && 0 <= x && x < M)
        return true;
    return false;
}
 
int days(vector<vector<int> > vt)
{
    int day = 1;
 
    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (vt[i][j] == 0)
                return -1;
            else if (day < vt[i][j])
                day = vt[i][j];
        }
    }
 
    return day - 1;
}
 
int main()
{
    cin >> M >> N;
 
    vector<vector<int> > vt(N, vector<int>(M));
    queue<pair<int, int> > qu;
     
    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<M; j++)
        {
            cin >> vt[i][j];
 
            if (vt[i][j] == 1)
                qu.push(make_pair(i, j));
        }
    }
     
    while (!qu.empty())
    {
        int a = qu.front().first;
        int b = qu.front().second;
        qu.pop();
 
        for (int i = 0; i<4; i++)
        {
            int nextY = a + dy[i];
            int nextX = b + dx[i];
 
            if (isRange(nextY, nextX) && vt[nextY][nextX] == 0) 
            {
                qu.push(make_pair(nextY, nextX));
                vt[nextY][nextX] = vt[a][b]+1;
            }
        }
    }
 
    cout << days(vt) << endl;
 
    return 0;
}