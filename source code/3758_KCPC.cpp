#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int T;
	cin>>T;

	for(int i=0;i<T;i++)
	{
		int n;//팀개수
		int k;//문제수
		int t;//우리팀
		int m;//로그
		cin>>n>>k>>t>>m;
		
		int id[100][100]={0};
		vector<int> total;
		vector<int>cnt;
		vector<int>sub;
		for(int i=0;i<n;i++)
		{
			total.push_back(0);
			cnt.push_back(0);
			sub.push_back(0);
		}
				
		for(int i=0;i<m;i++)
		{
			int tid;//팀
			int j;//문제번호
			int s;//점수
			cin>>tid>>j>>s;

			if(id[tid-1][j-1] < s)
			{
				total[tid-1] -= id[tid-1][j-1];
				id[tid-1][j-1] = s;
				total[tid-1] += id[tid-1][j-1];
			}
			cnt[tid-1]++;
			sub[tid-1] = i+1;
		}
		//지정

		int count = 0;
		for(int i=0;i<total.size();i++)
		{
			if(total[i] > total[t-1])
			{
				count++;
			}
			else if(total[i] == total[t-1] && cnt[i] < cnt[t-1])
			{
				count++;
			}
			else if(total[i] == total[t-1] && cnt[i] == cnt[t-1] && sub[i] < sub[t-1])
			{
				count++;
			}
		}
		
		cout<<count+1<<endl;
	
	}

	return 0;
}