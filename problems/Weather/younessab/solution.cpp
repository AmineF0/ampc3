#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<vector<ll>> vll;
vll id = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
ll mod = 1e9+7;

vll matrix_multi(vll a,vll b){
    vector<vector<ll>> res(4,vector<ll>(4,0));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                res[i][j] =(res[i][j]%mod+ (a[i][k]%mod*b[k][j]%mod)%mod)%mod;
            }
        }
    }
    return res;
}
vll binpow(vll a, ll b) {
    if (b == 0)
        return id;
    vll res = binpow(a, b / 2);
    if (b % 2)
        return matrix_multi(matrix_multi(res,res),a);
    else
        return matrix_multi(res,res);
}

int main(){
    int t;cin>>t;
     while(t--){
        vll mat ={{6,5,1,5},{1,1,0,7},{1,0,1,1},{0,0,0,1}};
        ll x0,y0,z0,n;cin>>x0>>y0>>z0>>n;
        vll res = binpow(mat,n);
        ll x = (res[0][0]*x0%mod+res[0][1]*y0%mod+res[0][2]*z0%mod+res[0][3])%mod;
        cout<<x<<endl;

     }
}
