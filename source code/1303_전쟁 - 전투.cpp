#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isRange(int i, int j, int M, int N)//배열 벗어나는거 체크용
{
    if (i < 0 || i >= M) 
		return false;
    if (j < 0 || j >= N) 
		return false;

    return true;
}

double count(vector<vector<char> > &vt, int i, int j, double &cnt,int M, int N, char c)
{
    vt[i][j] = c+32;
	
	for(int a=0;a<4;a++)
	{
		int ni = i + dy[a];
		int nj = j + dx[a];

		if (isRange(ni, nj, M, N) && vt[ni][nj] == c)
		{	
			count(vt, ni, nj, cnt, M, N, c);
		}
	}
	return ++cnt;
}
 
 
int main(void)
{
    int N, M;
    cin >> N >> M;//N은 열, M은 행
 
    vector<vector<char> > vt;
 
    for (int i = 0; i < M; i++)
    {
        vector<char> in;
        in.resize(N);
        vt.push_back(in);
    }
    //전쟁터
         
    string str[101];
     
    for (int i = 0; i < M; i++)
    {
        cin >> str[i];
 
        for (int j = 0; j < N; j++)
        {
            vt[i][j] = str[i].at(j);
        }
 
    }
     
    double cntB = 0, cntW = 0;
    double totalB = 0, totalW = 0;
 
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vt[i][j] == 'B')
            totalB += pow(count(vt, i, j, cntB, M, N, 'B'),2);
			cntB=0;

			if (vt[i][j] == 'W')
            totalW += pow(count(vt, i, j, cntW, M, N, 'W'),2);
			cntW=0;
			
        }
    }
    cout<<totalW<<" "<<totalB<<endl;
     
    return 0;
}
