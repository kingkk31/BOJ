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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

struct Node {
	int sum, cnt;
};

struct Point {
	int dx, start, end, flag;
	Point(int _dx, int _start, int _end, int _flag)
	{
		dx = _dx;
		start = _start;
		end = _end;
		flag = _flag;
	}
};

Node tree[100 * 8];
vector<Point> vt;

bool cmp(const Point &left, const Point &right)
{
	return left.dx < right.dx;
}

void solve(int pos, int start, int end, int left, int right, int flag)
{
	if (left > end || right < start)
		return;
	else if (left <= start && end <= right)
		tree[pos].cnt += flag;
	else
	{
		int mid = (start + end) / 2;
		solve(pos * 2, start, mid, left, right, flag);
		solve(pos * 2 + 1, mid + 1, end, left, right, flag);
	}

	if (tree[pos].cnt == 0)
		tree[pos].sum = tree[2 * pos].sum + tree[2 * pos + 1].sum;
	else
		tree[pos].sum = end - start + 1;
}

int main(void)
{
	int x1, y1, x2, y2;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		vt.push_back(Point(x1, y1, y2, 1));
		vt.push_back(Point(x2, y1, y2, -1));
	}

	int ans = 0, pre = vt[0].dx;
	sort(vt.begin(), vt.end(), cmp);

	for (int i = 0; i < vt.size(); i++)
	{
		ans += (vt[i].dx - pre) * tree[1].sum;
		solve(1, 1, 100, vt[i].start, vt[i].end - 1, vt[i].flag);
		pre = vt[i].dx;
	}
	printf("%d\n", ans);

	return 0;
}