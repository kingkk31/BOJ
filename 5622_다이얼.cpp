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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int time = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		switch (str[i])
		{
		case 'A': case 'B':	case 'C': time += 3; break;
		case 'D': case 'E':	case 'F': time += 4; break;
		case 'G': case 'H':	case 'I': time += 5; break;
		case 'J': case 'K':	case 'L': time += 6; break;
		case 'M': case 'N':	case 'O': time += 7; break;
		case 'P': case 'Q':	case 'R': case 'S': time += 8; break;
		case 'T': case 'U':	case 'V': time += 9; break;
		case 'W': case 'X':	case 'Y': case 'Z': time += 10; break;
		default: time += 2; break;
		}		
	
	cout << time << endl;

	return 0;
}