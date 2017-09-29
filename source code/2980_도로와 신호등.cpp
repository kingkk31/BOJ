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

typedef struct trafficLight {
	int place, red, green, timer;
	char sig;
}trafficLight;

int main(void)
{
	int n, l;
	scanf("%d %d", &n, &l);

	vector<trafficLight> traffic(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &traffic[i].place, &traffic[i].red, &traffic[i].green);
		traffic[i].sig = 'r';
		traffic[i].timer = 0;
	}

	int pos = 0, time = 0, tpos = 0;
	while (pos < l)
	{
		time++;

		if (tpos >= n)
			pos++;
		else 
		{
			if (pos == traffic[tpos].place)
			{
				if (traffic[tpos].sig == 'g')
				{
					pos++;
					tpos++;
				}
			}
			else
				pos++;
		}

		for (int i = 0; i < n; i++)
		{
			traffic[i].timer++;
			if (traffic[i].sig == 'r' && traffic[i].red <= traffic[i].timer)
			{
				traffic[i].timer = 0;
				traffic[i].sig = 'g';
			}
			else if (traffic[i].sig == 'g' && traffic[i].green <= traffic[i].timer)
			{
				traffic[i].timer = 0;
				traffic[i].sig = 'r';
			}
		}
	}

	printf("%d\n", time);

	return 0;
}