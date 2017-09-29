#include <iostream>
using namespace std;
 
int main(void)
{
    int n;
    cin >> n;
 
    for (int i = n - 1; i >= 0; i--)
    {
        for (int a = n-1; a>i; a--)
        {
            cout << " ";
        }
        for (int j = (2 * i)+1; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
		
	for (int i = 1; i < n; i++)
    {
        for (int a = n-1; a>i; a--)
        {
            cout << " ";
        }
        for (int j = (2 * i)+1; j > 0; j--)
        {
            cout << "*";
        }
		cout << endl;
    }
  
    return 0;
}
 