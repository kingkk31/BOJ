#include <stdio.h>
#include <set>
using namespace std;

int main(void)
{
	int N;
	scanf("%d",&N);
	
	set<int> s;

	int i;
	for(i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		s.insert(a);
	}

	for(int i=N;i<N*N;i++)
	{
		int a;
		scanf("%d",&a);
		s.insert(a);
		s.erase(s.begin());
	}
	set<int>::iterator iter = s.begin();
	printf("%d\n", *iter);

	return 0;
}