#include <bits/stdc++.h>
using namespace std;

int main()
{
  double x1, x2, y1, y2, x3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3;
  // slope of line
  double m = (y2 - y1) / (x2 - x1);
  // y-intercept
  double c = y1 - m * x1;
  // y-coordinate of the point
  double y3 = m * x3 + c;
  cout << fixed << setprecision(8) << y3 << endl;
}