#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> pos;
vector<int> height;
 
int main() 
{
    int N;
    cin >> N;
 
    vector<int> top;
    top.push_back(0);
    for (int i = 0; i < N; i++) 
    {
        int h;
        cin >> h;
        top.push_back(h);
    }
     
    pos.assign(N + 1, 0);
    height.assign(N + 1, 0);
 
    for (int i = 2; i <= N; i++)
     {
        for (int j = i - 1; j >= 1; j--) 
        {
            if (top[i] <= top[j])
             {
                pos[i] = j;
                height[i] = top[j];
                break;
            }
            
            if (top[i] > top[j])
             {
                j = pos[j];
                j++;
            } 
        }
    }
 
    for (int i = 1; i <= N; i++)
        cout << pos[i] << " ";

    return 0;
}