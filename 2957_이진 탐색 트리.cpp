#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stdio.h>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
	int N; 
	//cin >> N;
	scanf("%d", &N);

	map<int, unsigned long long>m;
	int root;
	unsigned long long total = 0;
	//cin >> root;
	scanf("%d", &root);
	m[root] = 0;
	//cout << total << endl;
	printf("%d\n", total);

	for (int i = 0; i < N-1; i++) {
		int X;
		//cin >> X;
		scanf("%d", &X);

		int value = -1;
		m[X] = value;
		map<int, unsigned long long>::iterator itr = m.find(X);

		if (itr == m.begin()) {
			map<int, unsigned long long>::iterator temp = itr;
			++temp;
			itr->second = temp->second + 1;
		}
		else if (++itr == m.end()) {
			--itr;
			map<int, unsigned long long>::iterator temp = itr;
			--temp;
			itr->second = temp->second + 1;
		}
		else {
			--itr;
			map<int, unsigned long long>::iterator temp1, temp2;
			temp1= itr;
			--temp1;
			temp2 = itr;
			++temp2;
			itr->second = max(temp1->second, temp2->second) + 1;
		}	
		total += itr->second;

		//cout << total << endl;
		printf("%llu\n", total);
	}
}
