#include <bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;
  while(t--){
    long long n; cin >> n;
    vector<int> v(n, 32);
    for(int i = 0; i < n; i++){
      long long a ; cin >> a;
      for(int i=0; i<32; i++){
        v[i] += (a & (1<<i)) >> i;
      }
      long long ans = 0;
      for(int i = 0; i < 32; i++){
        int bit = 0;
        if(v[i] >= n-v[i]){
          bit = 1;
        } 
        ans |= (bit<<i);
      }
    }
  }


  return 0;
}