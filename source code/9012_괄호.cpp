#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int main(void)
{
    int n;
    cin>>n;
 
    string* a = new string[n];
 
    for(int i=0;i<n;i++)
    {   
        stack<char> st;
 
        cin>>a[i];
 
        for(int j=0;j<a[i].length();j++)
        {
            if(a[i].at(j) == '(')
                st.push('(');
            else if(a[i].at(j) == ')')
            {
                if(!st.empty())
                    st.pop();
                else
                {
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if(j==a[i].length() -1)
            {
                if(!st.empty())
                    cout<<"NO"<<endl;
                else
                    cout<<"YES"<<endl;
            }
        }
    }
 
    return 0;
}