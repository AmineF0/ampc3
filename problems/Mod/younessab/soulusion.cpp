#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long ld;


void build(vector<ll>&a,vector<ll>&t,vector<ll>&mx, ll pos, ll tl, ll tr) {
    if (tl == tr) {
        t[pos] = a[tl];
        mx[pos]=a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a,t,mx, pos*2+1, tl, tm);
        build(a, t,mx,pos*2+2, tm+1, tr);
        t[pos] = t[pos*2+1] + t[pos*2+2];
        mx[pos]=max(mx[2*pos+1],mx[2*pos+2]);
    }
}



ll query(ll pos, ll tl, ll tr, ll l, ll r, vector<ll>&t) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[pos];
    }
    ll tm = (tl + tr) / 2;
    return query(pos*2+1, tl, tm, l, min(r, tm),t)
           + query(pos*2+2, tm+1, tr, max(l, tm+1), r,t);
}

void update(ll pos, ll tl, ll tr, ll posval, ll new_val,vector<ll>&t,vector<ll>&mx) {
    if (tl == tr) {
        t[pos] = new_val;
        mx[pos] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (posval <= tm)
            update(pos*2+1, tl, tm, posval, new_val,t,mx);
        else
            update(pos*2+2, tm+1, tr, posval, new_val,t,mx);
        t[pos] = t[pos*2+1] + t[pos*2+2];
        mx[pos]=max(mx[2*pos+1],mx[2*pos+2]);
    }
}




void updaterange(ll pos, ll tl, ll tr, ll l, ll r, ll add,vector<ll>&t,vector<ll>&mx) {
    if (l > r || tl>r || l>tr||mx[pos]<add )
        return;
    if (tl==tr) {
        t[pos] %= add;
        mx[pos]%=add;
    } else {
        ll tm = (tl + tr) / 2;
        updaterange(pos*2+1, tl, tm, l, r, add,t,mx);
        updaterange(pos*2+2, tm+1, tr, l, r, add,t,mx);
        t[pos]=t[2*pos+1]+t[2*pos+2];
        mx[pos]=max(mx[2*pos+1],mx[2*pos+2]);
    }
}



int main(){
    int n,m;cin>>n>>m;
    vector<ll>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<ll>st(4*n,0);
    vector<ll>mx(4*n,0);
    build(nums,st,mx,0,0,n-1);
    while(m--){
        ll type;cin>>type;
        if(type==1){
            ll left,right;cin>>left>>right;
            ll tmp=min(left,right);
            right=max(left,right);
            left=tmp;
            left--;right--;
            cout<<query(0,0,n-1,left,right,st)<<endl;
        }
        if(type==3){
            ll left,right,x;cin>>left>>right>>x;
            ll tmp=min(left,right);
            right=max(left,right);
            left=tmp;
            left--;right--;
            
            updaterange(0,0,n-1,left,right,x,st,mx);
            
        }
        if(type==2){
            ll pos,x;cin>>pos>>x;
            pos--;
            update(0,0,n-1,pos,x,st,mx);
            
        }
    }
}