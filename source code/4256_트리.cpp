#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> slice(const vector<int>& v, int a, int b)
{
    return vector<int>(v.begin() + a, v.begin() + b);
}
 
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
    const int N = preorder.size();
    if(preorder.empty())
        return;
 
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    const int R = N - 1 - L;
 
    printPostOrder(slice(preorder,1,L+1), slice(inorder,0,L));
    printPostOrder(slice(preorder,L+1,N), slice(inorder,L+1,N));

	 cout<<root<<' ';
}
 
int main(void)
{
    int T;
	cin>>T;

	for(int a=0;a<T;a++)
	{
		int n;
		cin>>n;

		vector<int> preorder;
		vector<int> inorder;

		for(int i=0;i<n;i++)
		{
			int num;
			cin>>num;
			preorder.push_back(num);
		}

		for(int i=0;i<n;i++)
		{
			int num;
			cin>>num;
			inorder.push_back(num);
		}

		printPostOrder(preorder,inorder);

		cout<<endl;
	}

	return 0;
}
