#include <bits/stdc++.h>
using namespace std;

void solve()
{
  map<string, long long> mp;

  long long n;
  cin >> n;

  long long m;
  cin >> m;
  for (long long i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    long long x;
    cin >> x;
    mp[s] = x;
  }

  long long sum = 0;

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