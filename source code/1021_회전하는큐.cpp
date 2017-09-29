#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main(void)
{
  list<int> li;
  int n,m;
    cin>>n>>m;
  for(int i=0;i<n;i++)
    li.push_back(i+1);
  
  list<int>::iterator itr = li.begin();
  int cou = 0; 
  
  for(int i=0;i<m;i++)
  {
    int a;
    cin>>a;
    int c = 0;
     
    list<int>::iterator itr2 = find(li.begin(),li.end(),a);
    while(itr != itr2)
    {
      itr++;
      c++;
    }

    int d = *itr;
    itr = li.begin();
    if(c > (li.size()/2))
    {
      while(*itr != d)
      {
       li.push_front(li.back());
       itr = li.begin();
       li.pop_back();
       cou++;
      }
    }
    else
    { 
     while(*itr != d)
     {
      li.push_back(li.front());
         itr++;
      li.pop_front();
      cou++;
     }
    }

    li.pop_front();
    itr = li.begin(); 
  }
  
  cout<<cou<<endl;
  return 0;
}