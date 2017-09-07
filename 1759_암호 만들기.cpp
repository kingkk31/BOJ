#include <iostream>
#include <algorithm>
using namespace std;

int L,C;
char al[16];
char pick[16];
int cnt=0; //pick[]위치;

bool isVowel(char a)
{
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return true;
	else
		return false;
}

void make(int num, int place, int con, int vowel) //뽑은수, al[]위치, 자음, 모음
{
	if(num == 0 && con >= 2 && vowel >= 1)
	{
		cout<<pick<<endl;
		return;
	}
	
	for(int i=place;i<C;i++)
	{
		if(isVowel(al[i]))
			vowel++;
		else con++;

		pick[cnt] = al[i];
		cnt++;

		make(num-1,i+1,con,vowel); // 뽑았으니 다음칸으로 재귀호출

		//다른경우 조사위해 다시 그 부분 지움
		if(isVowel(al[i])) 
			vowel--;
		else con--;

		cnt--;
		pick[cnt] = 0;
	}
}

int main(void)
{
	cin>>L>>C;

	for(int i=0;i<C;i++)
	{
		cin>>al[i];
	}

	sort(al,al+C);

	int con=0, vowel=0;
	make(L,0,con,vowel);

    return 0;
}
