#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;
int main(){
    int t;cin>>t;
    while(t--){
        ll x0,y0,z0,n;cin>>x0>>y0>>z0>>n;
        for (int i=0;i<n;i++){
            ll x = (6*x0%mod+5*y0%mod+z0%mod+5)%mod;
            ll y = (x0%mod+y0%mod+7)%mod;
            ll z = (z0%mod+1+x0%mod)%mod;
            x0 = x;
            y0 = y;
            z0 = z;
        }
        cout<<x0<<endl;
    }
}