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

typedef struct student {
	int want, flag, depth; //친구, 확인여부(시작점마다 다름), 길이
}student;

int cnt;
vector<student> vt;

void solve(int pos, int flag, int depth)
{
	if (vt[pos].flag != -1 && vt[pos].flag != flag) //다음 사람이 확인됬는데 시작점과 다를 경우
		return;
	
	if (vt[pos].flag == -1) //확인되지 않은 경우
	{
		vt[pos].flag = flag; //현 위치의 확인상태를 시작점으로 갱신
		vt[pos].depth = depth; //현재 위치에서의 길이 복사
		solve(vt[pos].want, flag, depth + 1);
	}
	else
		cnt += (depth - vt[pos].depth); //확인되고 시작점과 같을 경우(사이클일 경우)
		//현재까지 방문한 길이에서 다음 사람에게 저장된 방문길이를 뺀 값이 사이클의 크기
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		cnt = 0;
		scanf("%d", &n);
		vt = vector<student>(n + 1);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &vt[i].want);
			vt[i].flag = -1;
		}

		for (int i = 1; i <= n; i++)
			solve(i, i, 0);
		printf("%d\n", n - cnt);
	}

	return 0;
}
