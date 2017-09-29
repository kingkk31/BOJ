#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
 
vector<vector<int> > vt;
queue<int> qu;
 
void BFS(int *to, int *time, int *totalTime)
{
    while (!qu.empty()) 
    {   
        int here = qu.front();
        qu.pop();
        totalTime[here] += time[here];
 
        for (int j = 0; j < vt[here].size(); j++) 
        {
            int next = vt[here][j];
            totalTime[next] = max(totalTime[next], totalTime[here]);
             
            to[next]--;
            if (to[next] > 0) 
                continue;
 
            qu.push(next);
        }
    }
}
 
int main(void) 
{
    int T;
    cin >> T;
 
    for (int i = 0; i < T; i++)
    {
        int N, K; 
        cin >> N >> K;
 
        vt = vector<vector<int> >(N + 1);       
 
        int *to = new int[N + 1];
        int *totalTime = new int[N + 1];
        int *time = new int[N + 1];
 
        for (int j = 0; j < N + 1; j++)
        {
            to[j] = 0;
            totalTime[j] = 0;
        }
 
        time[0] = 0;
 
        for (int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            time[j] = a;
        }
 
        for (int j = 0; j < K; j++)
        {
            int a, b;
            cin >> a >> b;
            vt[a].push_back(b);
            to[b]++;
        }
 
        for (int j = 1; j <= N; j++)
            if (to[j] == 0)
                qu.push(j);
         
        int must;
        cin >> must;
 
        BFS(to,time,totalTime);
        cout<< totalTime[must] <<endl;
    }
 
    return 0;
}