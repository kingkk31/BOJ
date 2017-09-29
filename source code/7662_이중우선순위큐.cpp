#include <iostream>
#include <set>
using namespace std;
 
int main(void)
{  
    int T;
    cin>>T;
     
    for(int i=0;i<T;i++)
    {
        multiset<int> Q;
 
        int R;
        cin>>R;
 
        for(int j=0;j<R;j++)
        {
            char H;
            int W;
 
            cin>>H>>W;
 
            if(H == 'I')
                Q.insert(W);
            else if(H == 'D')
            {
                if(Q.begin() == Q.end())
                    continue;
                else
                {
                    if(W == -1)
                        Q.erase(Q.begin());
                    else if(W == 1)
                        Q.erase(--Q.end());
                }               
            }       
        }
 
        if(Q.begin() == Q.end())
            cout<<"EMPTY"<<endl;
        else
            cout<<*(--Q.end())<<" "<<*Q.begin()<<endl;
    }   
     
    return 0;
}