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
#pragma warning(disable:4996)
using namespace std;

int n;
vector<vector<int> > vt;
vector<int> degree;

void eulerCircuit(int pos, vector<int> &circuit)
{
	for (int i = 0; i < vt.size(); i++)
		while (vt[pos][i] > 0)
		{
			vt[pos][i]--;
			vt[i][pos]--;
			eulerCircuit(i, circuit);
		}
	circuit.push_back(pos);
}

int main(void)
{
	cin >> n;
	vt = vector<vector<int> >(n, vector<int>(n));
	degree = vector<int>(n, 0);
	vector<int> circuit;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &vt[i][j]);
			degree[i] += vt[i][j];
		}
	for (int i = 0; i < n;i++)
		if (degree[i] == 0 || degree[i] % 2 != 0)
		{
			cout << -1 << endl;
			return 0;
		}
	
	eulerCircuit(0, circuit);

	for (int i = circuit.size() - 1; i >= 0; i--)
		cout << circuit[i] + 1 << " ";
	
	return 0;
}