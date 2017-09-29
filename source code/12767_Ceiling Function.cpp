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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

typedef struct tree {
	int num;
	tree *left, *right;

	tree(int n)
	{
		num = n;
		left = NULL;
		right = NULL;
	}

}tree;

string intToString(int n)
{
	stringstream s;
	s << n;
	return s.str();
}

void inorder(tree *t, string &str, int cnt)
{
	str += intToString(cnt);

	if (t->left != NULL)
	{
		str += "l";
		inorder(t->left, str, cnt + 1);
	}

	if (t->right != NULL)
	{
		str += "r";
		inorder(t->right, str, cnt + 1);
	}
}

void insert(tree **t, int num)
{
	if (*t == NULL)
	{
		tree *node = new tree(num);
		*t = node;
	}
	else
	{
		if ((*t)->num > num)
			insert(&(*t)->left, num);
		else
			insert(&(*t)->right, num);
	}
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	set<string> st;

	while (n--)
	{
		tree *t = NULL;
		for (int i = 0; i < k; i++)
		{
			int num;
			scanf("%d", &num);
			insert(&t, num);
		}
		string str = "";
		int cnt = 0;
		inorder(t, str, cnt);
		st.insert(str);
	}
	printf("%d\n", st.size());

	return 0;
}