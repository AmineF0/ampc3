#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double long ld;


void build(vector<ll>&a,vector<ll>&t, ll pos, ll tl, ll tr) {
    if (tl == tr) {
        t[pos] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a,t, pos*2+1, tl, tm);
        build(a, t,pos*2+2, tm+1, tr);
        t[pos] = t[pos*2+1] + t[pos*2+2];
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

void update(ll pos, ll tl, ll tr, ll posval, ll new_val,vector<ll>&t) {
    if (tl == tr) {
        t[pos] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (posval <= tm)
            update(pos*2+1, tl, tm, posval, new_val,t);
        else
            update(pos*2+2, tm+1, tr, posval, new_val,t);
        t[pos] = t[pos*2+1] + t[pos*2+2];
    }
}






void updatemod(ll pos, ll tl, ll tr, ll posval, ll new_val,vector<ll>&t) {
    if (tl == tr) {
        t[pos] %= new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (posval <= tm)
            updatemod(pos*2+1, tl, tm, posval, new_val,t);
        else
            updatemod(pos*2+2, tm+1, tr, posval, new_val,t);
        t[pos] = t[pos*2+1] + t[pos*2+2];
    }
}

int main(){
    int n,m;cin>>n>>m;
    vector<ll>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<ll>st(4*n,0);
    build(nums,st,0,0,n-1);
    // for(int i=0;i<4*n;i++){
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
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
            for(int i=left;i<=right;i++){
                updatemod(0,0,n-1,i,x,st);
            }
        }
        if(type==2){
            ll pos,x;cin>>pos>>x;
            pos--;
            update(0,0,n-1,pos,x,st);
        }
    }
}