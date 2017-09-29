#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool right(string str, int num)
{
	vector<int> vt;

	int a = str[0]-48;
	vt.push_back(a);
		
	for(int i=1;i<str.size()-1;i+=2)
	{
		if(str[i] == '+')
		{
			int b = str[i+1]-48;
			vt.push_back(b);
		}
		else if(str[i] == '*')
		{
			int b = str[i+1]-48;
			vt.back() *= b; 
		}
	}

	int total = 0;

	for(int i=0;i<vt.size();i++)
	{
		total += vt[i];
	}

	if(total == num)
		return true;

	return false;
}

bool wrong(string str, int num)
{
	int a = str[0]-48;
	
	for(int i=1;i<str.size()-1;i+=2)
	{
		if(str[i] == '+')
		{
			int b = str[i+1]-48;
			a+=b;
		}
		else if(str[i] == '*')
		{
			int b = str[i+1]-48;
			a*=b; 
		}
	}

	if(a == num)
		return true;

	return false;
}

int main(void)
{  
	string str;
	cin>>str;

	int num;
	cin>>num;

	bool isRight = right(str,num);
	bool isWrong = wrong(str,num);

	if(isRight && isWrong)
		cout<<"U"<<endl;
	else if(isRight && !isWrong)
		cout<<"M"<<endl;
	else if(!isRight && isWrong)
		cout<<"L"<<endl;
	else
		cout<<"I"<<endl;
	
    return 0;
}