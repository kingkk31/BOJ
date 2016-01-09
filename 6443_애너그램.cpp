#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>
using namespace std;
 
void make(int num, string str, vector<char> &vt, vector<vector<char> > &st, int *cache)
{
    if (num == 0)
    {
        st.push_back(vt);
        return;
    }
 
    char temp= ' ';
 
    for (int i = 0; i<str.length(); i++)
    {
        if (cache[i] != 1 && temp!=str[i])
        {
            temp = str[i];
 
            vt.push_back(temp);
            cache[i] = 1;
            make(num - 1, str, vt, st, cache);
            cache[i] = -1;
            vt.pop_back();
 
        }
    }
}
 
int main(void)
{
    int T;
    scanf("%d", &T);
 
    for (int a = 0; a<T; a++)
    {
        string str;
        cin >> str;
 
        vector<vector<char> > st;
        vector<char> vt;
 
        sort(str.begin(), str.end());
 
        int *cache = new int[str.length()];
        memset(cache, -1, sizeof(cache));
 
        make(str.length(), str, vt, st, cache);
 
 
        vector<vector<char> >::iterator itr = st.begin();
 
        while (itr != st.end())
        {
            for (int i = 0; i<(*itr).size(); i++)
                printf("%c", (*itr)[i]);
            printf("\n");
            itr++;
        }
    }
    return 0;
}