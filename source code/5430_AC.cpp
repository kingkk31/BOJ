#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
 
int main(void)
{
    int T;
    scanf("%d",&T);
 
    for(int i=0;i<T;i++)
    {   
        char p[300000];
        scanf("%s", p);
        string call(p);
 
        int n,temp;
        list<int> vt;
        scanf("%d", &n);
        getchar(); 
       
        if (n == 0)
            scanf("[]");
        else{
            scanf("[");
            for (int a = 0; a < n - 1; a++){
                scanf("%d,", &temp);
                vt.push_back(temp);
            }
            scanf("%d]", &temp);
            vt.push_back(temp);
        }
 
        bool ch = false;
        bool right = true;
 
        for (int i = 0; i<call.length(); i++)
        {
            if (call[i] == 'R')
            {
                if (n == 0)
                    continue;
                else
                {
                    if(!ch)
                        ch = true;
                    else
                        ch = false;
                }
            }
            else if (call[i] == 'D')
            {
                if (vt.empty())
                    right = false;
                else
                {
                    if(!ch)
                        vt.pop_front();
                    else
                        vt.pop_back();
                }
            }
        }
 
        if(ch)
            reverse(vt.begin(), vt.end());
         
        if(right)
        {
            if (vt.empty())
                printf("[]\n");
            else
            {
                int back = vt.back();
                vt.pop_back();
                printf("[");
                for (list<int>::iterator it = vt.begin(); it != vt.end(); it++)
                    printf("%d,", *it);
                printf("%d]\n",back);
            }
        }
        else
            printf("error\n");
    }
 
    return 0;
}