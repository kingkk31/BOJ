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
#include <time.h>
#include <cctype>
#pragma warning(disable:4996)
using namespace std;

vector<vector<int> >  vt;
vector<set<int> > vtst;
int cnt;

int cToi(char c)
{
	if ('A' <= c && c <= 'Z')
		return (int)(c - 'A');
	else
		return (int)(c - 'a') + 26;
}

char iToc(int i)
{
	if ((int)'A' <= i + (int)'A' && i + (int)'A' <= (int)'Z')
		return (char)(i + (int)'A');
	else
		return (char)(i + (int)'a' - 26);
}

void bfs(int start)
{
	queue<int> qu;
	vector<bool> visited(52, false);
	set<int> st;
	qu.push(start);
	visited[start] = true;

	while (!qu.empty())
	{
		int pos = qu.front();
		qu.pop();

		for (int i = 0; i < vt[pos].size(); i++)
		{
			int next = vt[pos][i];
			if (!visited[next])
			{
				visited[next] = true;
				qu.push(next);
				st.insert(next);
			}
		}
	}

	vtst[start] = st;
	cnt += st.size();
}

int main(void)
{
	int n;
	scanf("%d", &n);
	char c = getchar();
	vt = vector<vector<int> >(52);
	vtst = vector<set<int> >(52);
	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		vt[cToi(str[0])].push_back(cToi(str[str.length() - 1]));
	}

	for (int i = 0; i < 52; i++)
		bfs(i);
	
	cout << cnt << endl;
	for (int i = 0; i < 52; i++)
	{
		set<int>::iterator itr = vtst[i].begin();
		char from = iToc(i);
		while (itr != vtst[i].end())
		printf("%c => %c\n", from, iToc(*itr++));
	}

	return 0;
}