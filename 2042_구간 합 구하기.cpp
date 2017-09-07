#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stdio.h>
using namespace std;

struct FenwickTree{
	vector<long long> tree;
	FenwickTree(int n) : tree(n + 1, 0){}

	long long sum(int pos){
		long long  ret = 0;
		while (pos > 0){
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void add(int pos, long long val){
		while (pos < tree.size()){
			tree[pos] += val;
			pos += (pos&-pos);
		}
	}
	void printTree(){
		for (int i = 0; i < tree.size(); i++)
			cout << tree[i] << ' ';
		cout << endl;
	}
};

int main(){
	int n, m, k; cin >> n >> m >> k;
	FenwickTree tree(n);

	for (int i = 1; i <= n; i++){
		int data; cin >> data;
		tree.add(i, data);
	}

	int time = m + k;

	while (time--){
		long long a, b, c; cin >> a >> b >> c;

		if (a == 1){
			tree.add(b, c - (tree.sum(b) - tree.sum(b - 1)));

		}
		else{
			cout << tree.sum(c) - tree.sum(b - 1) << endl;
		}
	}

	return 0;
}