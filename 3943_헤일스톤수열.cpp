#include <iostream>
using namespace std;
 
int main(void)
{
    int T;
    cin >> T;
 
    for (int i = 0; i < T; i++)
    {
        int num;
        cin >> num;
        int max = num;
 
        while (num != 1)
        {
            if (num % 2 == 0)
                num /= 2;
            else
                num = (num * 3)+1;
 
            if (num > max)
                max = num;
        }
 
        cout << max << endl;
 
    }
     
    return 0;
}