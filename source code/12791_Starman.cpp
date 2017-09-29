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

#define mk make_pair

int main(void)
{
	vector<pair<int, string> > album(25);
	album[0] = mk(1967, "DavidBowie");
	album[1] = mk(1969, "SpaceOddity");
	album[2] = mk(1970, "TheManWhoSoldTheWorld");
	album[3] = mk(1971, "HunkyDory");
	album[4] = mk(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	album[5] = mk(1973, "AladdinSane");
	album[6] = mk(1973, "PinUps");
	album[7] = mk(1974, "DiamondDogs");
	album[8] = mk(1975, "YoungAmericans");
	album[9] = mk(1976, "StationToStation");
	album[10] = mk(1977, "Low");
	album[11] = mk(1977, "Heroes");
	album[12] = mk(1979, "Lodger");
	album[13] = mk(1980, "ScaryMonstersAndSuperCreeps");
	album[14] = mk(1983, "LetsDance");
	album[15] = mk(1984, "Tonight");
	album[16] = mk(1987, "NeverLetMeDown");
	album[17] = mk(1993, "BlackTieWhiteNoise");
	album[18] = mk(1995, "1.Outside");
	album[19] = mk(1997, "Earthling");
	album[20] = mk(1999, "Hours");
	album[21] = mk(2002, "Heathen");
	album[22] = mk(2003, "Reality");
	album[23] = mk(2013, "TheNextDay");
	album[24] = mk(2016, "BlackStar");
	
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int s, e, cnt = 0, start = -1;
		cin >> s >> e;

		for (int i = 0; i < 25; i++)
		{
			if (album[i].first >= s && album[i].first <= e)
			{
				if (start == -1)
					start = i;
				cnt++;
			}
		}

		cout << cnt << endl;
		if(cnt != 0)
			for (int i = start; i < start + cnt; i++)
				cout << album[i].first << " " << album[i].second << endl;
	}

	return 0;
}