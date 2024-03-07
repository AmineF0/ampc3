#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ld moy0=0,moy1=0;
        for(int i=0;i<n;i++){
            ld x;cin>>x;
            moy0+=x;
        }
        for(int i=0;i<n;i++){
            ld x;cin>>x;
            moy1+=x;
        }
        if(moy0/n>moy1/n){
            cout<<0<<endl;
        }else if(moy0/n<moy1/n){
            cout<<1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}