#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
 
int main(void) 
{
	int N;
	cin>>N;
	set<int> st;

	for(int i=0;i<N;i++)
	{
		int num;
		cin>>num;
		st.insert(num);
	}
    
	set<int>::iterator itr = st.begin();

	while(itr != st.end())
		cout<<*(itr++)<<" ";
 
    return 0;
}
