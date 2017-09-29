#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
   int T;
   cin >> T;

   for (int i = 0; i < T; i++)
   {
      double x1, y1, x2, y2;
      int r1, r2;
      cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

      if (r1 < r2)
      {
         int temp;
         temp = r1;
         r1 = r2;
         r2 = temp;
      }

      double d;
      d = sqrt((pow((x1-x2),2))+(pow((y1-y2),2)));

      if ((x1 == x2) && (y1 == y2))
      {
         if (r1 == r2)
            cout << "-1" << endl;
         else
            cout << "0" << endl;
      }
      else
      {
         if ((r1 + r2)<d || (r1 - r2)>d)
            cout << "0" << endl;
         else if ((r1 + r2) == d || (r1 - r2) == d)
            cout << "1" << endl;
         else if ((r1 - r2) < d && d < (r1 + r2))
            cout << "2" << endl;
      }
   }

   return 0;
}