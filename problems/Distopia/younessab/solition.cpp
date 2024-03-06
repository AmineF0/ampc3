#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;cin>>t;
    while(t--){
        long long n;cin>>n;
        vector<int> acc1(32,0);
        vector<int> acc0(32,0);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            for(int j=0;j<32;j++){
                if(x&(1<<j)){
                    acc1[j]++;
                }else{
                    acc0[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(acc1[i]>=acc0[i]){
                ans+=(1<<i);
            }
        }
        cout<<ans<<endl;

    }
}