#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

vector<vector<int> > vt;
queue<int> qu;
int to[1001];
int Node[1001];

void BFS()
{
	while (!qu.empty()) 
	{	
		int here = qu.front();
		qu.pop();
		
		for (int j = 0; j < vt[here].size(); j++) 
		{
			int next = vt[here][j];
			Node[next] = max(Node[next], Node[here]);
			int num = 0;

			to[next]--;
			if (to[next] > 0)
				continue;

			for (int a = 1; a < vt.size(); a++)
			{
				vector<int>::iterator itr = find(vt[a].begin(), vt[a].end(), next);
				if (itr != vt[a].end() && Node[a] == Node[next])
					num++;
			}
					
			if (num > 1)
			   ++Node[next];
			
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
		int K,M,P;
		cin >> K >> M >> P;

		vt = vector <vector<int> >(M + 1);
				
		memset(to, 0, sizeof(to));
		memset(Node, 0, sizeof(Node));
		
		for (int j = 0; j < P; j++)
		{
			int a, b;
			cin >> a >> b;
			vt[a].push_back(b);
			to[b]++;
		}

		for (int j = 1; j <= M; j++)
		{
			if (to[j] == 0)
			{
				Node[j] = 1;
				qu.push(j);
			}
		}

		BFS();

		int maxi = Node[1];

		for (int j = 1; j <= M; j++)
			maxi = max(maxi, Node[j]);

		cout << K << " " << maxi <<endl;
	}

	return 0;
}