#include <iostream>
using namespace std;
 
int main(void)
{
    int n;
    cin >> n;
 
    for (int i = 1; i <= n; i++)
    {
		for (int a = n; a>n-i+1; a--)
        {
            cout << " ";
        }
		
		for (int j = (2 * i) - 1; j <=(2 * n) - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
 
    return 0;
}