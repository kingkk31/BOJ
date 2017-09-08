#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isRange(int i, int j, int N)//배열 벗어나는거 체크용
{
    if (i < 0 || i >= N) 
		return false;
    if (j < 0 || j >= N) 
		return false;

    return true;
}

double count(vector<vector<char> > &vt, int i, int j, int N, int &cnt)
{
    vt[i][j] = '0';
	
	for(int a=0;a<4;a++)
	{
		int ni = i + dy[a];
		int nj = j + dx[a];

		if (isRange(ni, nj, N) && vt[ni][nj] == '1')
		{	
			count(vt, ni, nj, N, cnt);
		}
	}
	return ++cnt;
}
 
int main(void)
{
    int N;
    cin >> N;
 
    vector<vector<char> > vt;
 
    for (int i = 0; i < N; i++)
    {
        vector<char> in;
        in.resize(N);
        vt.push_back(in);
    }
             
    string str[26];
	multiset<int> apart;
	
	int cnt = 0;
     
    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
 
        for (int j = 0; j < N; j++)
        {
            vt[i][j] = str[i].at(j);
        }
     }
	
	for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vt[i][j] == '1')
			{
				count(vt, i, j, N, cnt);
				apart.insert(cnt);
			}
			cnt = 0;
		}
	}
	
	multiset<int>::iterator itr = apart.begin();
	
	cout<<apart.size()<<endl;
	
	while(itr != apart.end())
	{
		cout<<*itr<<endl;
		itr++;
	}

    return 0;
}
