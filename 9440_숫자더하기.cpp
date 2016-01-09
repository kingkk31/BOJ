#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
  
int main(void)
{
    while(1)
    {
        int loop;
        cin>>loop;
 
        if(loop == 0)
            break;
         
        vector<int> vt;
        vector<int> one;
        vector<int> two;
 
        for(int i=0;i<loop;i++)
        {
            int num;
            cin>>num;
            vt.push_back(num);
        }
 
        sort(vt.begin(),vt.end());
 
        int siz = vt.size();
 
        if(siz%2 != 0)
        {
            vector<int>::iterator itr1 = vt.begin();
 
            while(itr1 != vt.end())
            {
                if(*itr1 != 0)
                    break;
                itr1++;
            }
 
            one.push_back(*itr1);
            vt.erase(itr1);
 
            while(vt.begin() != vt.end())
            {
                one.push_back(vt.front());
                vt.erase(vt.begin());
 
                if(two.begin() != two.end())
                {
                    two.push_back(vt.front());
                    vt.erase(vt.begin());   
                }
                else
                {
                    vector<int>::iterator itr2 = vt.begin();
 
                    while(itr2 != vt.end())
                    {
                        if(*itr2 != 0)
                            break;
                        itr2++;
                    }
 
                    two.push_back(*itr2);
                    vt.erase(itr2);
                }
            }
        }
        else
        {
            while(vt.begin() != vt.end())
            {
                if(one.begin() != one.end())
                {
                    one.push_back(vt.front());
                    vt.erase(vt.begin());   
                }
                else
                {
                    vector<int>::iterator itr1 = vt.begin();
 
                    while(itr1 != vt.end())
                    {
                        if(*itr1 != 0)
                            break;
                        itr1++;
                    }
 
                    one.push_back(*itr1);
                    vt.erase(itr1);
                }
 
                if(two.begin() != two.end())
                {
                    two.push_back(vt.front());
                    vt.erase(vt.begin());   
                }
                else
                {
                    vector<int>::iterator itr2 = vt.begin();
 
                    while(itr2 != vt.end())
                    {
                        if(*itr2 != 0)
                            break;
                        itr2++;
                    }
 
                    two.push_back(*itr2);
                    vt.erase(itr2);
                }
            }
        }
         
        reverse(one.begin(),one.end());
        reverse(two.begin(),two.end());
 
        int first=0,second=0;
 
        for(int i=0;i<one.size();i++)
            first += one[i]*pow((double)10,i);
 
        for(int i=0;i<two.size();i++)
            second += two[i]*pow((double)10,i);
 
        cout<<first+second<<endl;       
    }
     
    return 0;
}