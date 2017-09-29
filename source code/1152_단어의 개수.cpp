#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    int cnt = 1;
    int i = 0;
	int ch=0;
    getline(cin, str);
     
    for(; i < str.size(); i++)
	{
        if(str[i] != ' ')
			break;
    }
 
    for(; i < str.size(); i++)
	{
        ch++;
		if(str[i] == ' ' && i != str.size() - 1) 
			cnt++;
    }

	if(ch==0)
		cnt=0;

    cout<< cnt << endl;
}
