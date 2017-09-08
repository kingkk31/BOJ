#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int main(void)
{
	set<int> tree;
	
	int n;
	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);

		tree.insert(num);
	}

	set<int>::iterator itr = tree.begin();

	for(int i=0;i<n;i++)
	{
		printf("%d \n", *itr);
		itr++;
	}

	return 0;
}