#include <iostream>
using namespace std;

int main(void)
{	
    int T;
	cin>>T;

	for(int i=0;i<T;i++)
	{	
		int a,b;
		cin>>a>>b;
		int A = a%10;
		
		switch(A)
		{
		case 0 :
			cout<<"10"<<endl;
			break;

		case 1 :
			cout<<"1"<<endl;
			break;

		case 2 :            // 2 4 8 6
			if(b%4==1) 
				cout<<"2"<<endl;
			else if(b%4==2) 
				cout<<"4"<<endl;
			else if(b%4==3) 
				cout<<"8"<<endl;
			else if(b%4==0)
				cout<<"6"<<endl;
			break;

		case 3 :            // 3 9 7 1
			if(b%4==1) 
				cout<<"3"<<endl;
			else if(b%4==2) 
				cout<<"9"<<endl;
			else if(b%4==3) 
				cout<<"7"<<endl;
			else if(b%4==0) 
				cout<<"1"<<endl;
			break;

		case 4 :            // 4 6
			if(b%2==1)
				cout<<"4"<<endl;
			else if(b%2==0)
				cout<<"6"<<endl;
			break;

		case 5 :
			cout<<"5"<<endl;
			break;

		case 6 :
			cout<<"6"<<endl;
			break;

		case 7 :            // 7 9 3 1
			if(b%4==1) 
				cout<<"7"<<endl;
			else if(b%4==2) 
				cout<<"9"<<endl;
			else if(b%4==3) 
				cout<<"3"<<endl;
			else if(b%4==0)
				cout<<"1"<<endl;
			break;

		case 8 :            // 8 4 2 6
			if(b%4==1) 
				cout<<"8"<<endl;
			else if(b%4==2) 
				cout<<"4"<<endl;
			else if(b%4==3) 
				cout<<"2"<<endl;
			else if(b%4==0)
				cout<<"6"<<endl;
			break;

		case 9 :            // 9 1
			if(b%2==1) 
				cout<<"9"<<endl;
			else if(b%2==0) 
				cout<<"1"<<endl;
			break;

		default :
			break;
		}	
	}

	return 0;
}