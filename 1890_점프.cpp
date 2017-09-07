#include <iostream>
#include <string.h>
using namespace std;

unsigned long long board[101][101];
unsigned long long cache[101][101];
int N;

unsigned long long count(int y, int x)
{
	if(y >= N || x >= N)
		return 0;

	if(y == N-1 && x == N-1)
		return 1;
	
	unsigned long long &ret = cache[y][x];
	
	if(ret != -1)
        return ret;
    
    int jump = board[y][x]; 

	if(jump == 0)
		return 0;
        
	return ret = (count(y+jump,x) + count(y,x+jump));   
}
   
int main(void)
{
    cin >> N;
 
    memset(cache,-1,sizeof(cache));
      
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }  
    }
     
    cout<< count(0,0) << endl;
  
    return 0;
}
