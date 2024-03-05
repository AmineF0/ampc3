#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        map<string,double> items;
        for(ll i=0;i<n;i++){
            string s;double p;
            cin>>s>>p;
            items[s]=p;
        }
        double total=0;
        for(ll i=0;i<m;i++){
            string s;cin>>s;
            ll q;cin>>q;
            total+=items[s]*q;
        }
        cout<<total<<endl;
    }
}