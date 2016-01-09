#include <iostream>
#include <vector>
using namespace std;
 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
 
bool isRange(int i, int j, int m, int n)
{
    if (i < 0 || i >= n) 
        return false;
    if (j < 0 || j >= m) 
        return false;
 
    return true;
}
 
int count(vector<vector<int> > &vt, int i, int j, int m, int n)
{
    vt[i][j] = 2;
    for(int a=0;a<4;a++)
    {
        int ni = i + dy[a];
        int nj = j + dx[a];
 
        if (isRange(ni, nj, m, n) && vt[ni][nj] == 1)
            count(vt, ni, nj, m, n);
    }
     
    return 1;
}
 
int main(void)
{
    int T;
    cin>>T;
 
    for(int i=0;i<T;i++)
    {
        int m,n,k,num = 0;
        cin>>m>>n>>k;
 
        vector<vector<int> > vt(n,vecotr<int>(m,0));
  
        for(int i=0;i<k;i++)
        {
            int x,y;
            cin>>x>>y;
            vt[y][x] = 1;
        }
 
        for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
                 if(vt[i][j] == 1)
                    num += count(vt,i,j,m,n);
 
         cout<<num<<endl;
    }
 
    return 0;
}