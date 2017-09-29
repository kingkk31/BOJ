#include <iostream>
using namespace std;
 
int main(void)
{  
    int M,N;
    cin>>M>>N;
     
    if(M<=N)
        cout<<(M-1)*2<<endl;
    else
        cout<<(N*2)-1<<endl;
 
    return 0;
}
