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
#pragma warning(disable:4996)
using namespace std;
 
int main(void)
{
    int t;
    cin >> t;
 
    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
 
        vector<int> vt,num;
        vector<int> result(n);
         
        for (int i = 1; i <= n; i++)
        {
            int s;
            cin >> s;
            vt.push_back(s);
            num.push_back(i);
        }
 
        bool ch = false;
 
        for (int i = vt.size() - 1; i >= 0; i--)
        {
            if (vt[i] >= num.size())
            {
                cout << "IMPOSSIBLE" << endl;
                ch = true;
                break;
            }
            else
            {
                result[i] = *(num.begin() + vt[i]);
                num.erase(num.begin() + vt[i]);
            }
        }
        if (!ch)
        {
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
            cout << endl;
        }
    }
     
    return 0;
}