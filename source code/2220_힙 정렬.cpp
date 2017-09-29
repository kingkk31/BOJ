#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

void push_heap(vector<int>& heap, int newValue) {
	
	if (newValue == 1)
	{
		heap.push_back(1);
		return;
	}

	heap[heap.size() - 1] = newValue;
	 // 힙의 맨 끝에 삽입
	int idx = heap.size() - 1; // 추가한 노드의 현재 위치
	while (idx>0 && heap[(idx - 1) / 2]<heap[idx]) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	} // 부모 노드와 크기 규칙 만족
	heap.push_back(1);
}

int main()
{
	int n;
	cin >> n;

	vector<int> heap;

	for (int i = 1; i <= n; i++)
	{
		push_heap(heap, i);
	}

	for (int i = 0; i < heap.size(); i++)
		cout << heap[i] << " ";
	
	return 0;
}
