#include <iostream>
using namespace std;
 
int main(void)
{
    int cnt=0;
    int max=0;
    int train=0;
    int in,out;
 
    while(cnt<4)
    {
        cin>>out, cin>>in;
 
        train=train-out;
        train=train+in;
 
        if(train>max)
            max=train;
        cnt++;
    }
 
    cout<<max<<endl;
 
    return 0;
}