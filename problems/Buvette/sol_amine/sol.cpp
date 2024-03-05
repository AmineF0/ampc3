#include <bits/stdc++.h>
using namespace std;

void solve()
{
  map<string, double> mp;

  long long n;
  cin >> n;

  long long m;
  cin >> m;
  for (long long i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    double x;
    cin >> x;
    mp[s] = x;
  }

  double sum = 0;

  for (long long i = 0; i < m; i++)
  {
    string s;
    cin >> s;
    long long x;
    cin >> x;
    sum += mp[s] * x;
  }

  cout << sum << endl;
}

int main()
{
  long long t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}