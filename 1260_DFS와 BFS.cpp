#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > vt;
int N,M,V;
vector<bool> visited;

void DFS(int start)
{
	cout<<start+1<<" ";
	visited[start] = true;
		
	for(int i=0;i<N;i++)
	{
		if(vt[start][i] == 1 && !visited[i])
			DFS(i);
	}	
}

void BFS(int start)
{
	queue<int> qu;
	
	visited[start] = true;
	cout<<start+1<<" ";
	qu.push(start);
	
	while(!qu.empty())
	{
		int temp = qu.front();
		qu.pop();

		for(int i=0;i<N;i++)
		{	
			if(vt[temp][i] == 1 && !visited[i])
			{
				visited[i] = true;
				cout<<i+1<<" ";
				qu.push(i);
			}
		}	
	}
}

int main(void)
{
	cin>>N>>M>>V;

	vt.assign(N, vector<int>(N,0));
	
	for(int i=0;i<M;i++)
	{
		int from,to;
		cin>>from>>to;

		vt[from-1][to-1] = 1;
		vt[to-1][from-1] = 1;
	}
	
	visited = vector<bool>(vt.size(),false);
	DFS(V-1);

	cout<<endl;
	
	visited = vector<bool>(vt.size(),false);
	BFS(V-1);

	return 0;
} 