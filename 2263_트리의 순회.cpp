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
#pragma warning(disable:4996)
using namespace std;

vector<int> inorder;
vector<int> postorder;
int n;

void printPreOrder(int li, int ri, int lp, int rp)
{
	int N = rp - lp;
	
	const int root = postorder[rp];
	const int rootPoint = (find(inorder.begin(), inorder.end(), root) - inorder.begin());
	const int pSize = rootPoint - li;

	cout << root << ' ';
	if(pSize != 0)
		printPreOrder(li, rootPoint -1, lp, lp + pSize - 1);
	if(N-pSize != 0)
		printPreOrder(rootPoint + 1, ri - 1, lp + pSize, rp-1);
}

int main(void)
{
	cin >> n;

	for (int i = 0; i<n; i++)
	{
		int num;
		cin >> num;
		inorder.push_back(num);
	}

	for (int i = 0; i<n; i++)
	{
		int num;
		cin >> num;
		postorder.push_back(num);
	}

	printPreOrder(0, n-1, 0, n-1);

	return 0;
}

