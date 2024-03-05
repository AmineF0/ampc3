#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll m,n;cin>>n;
    unordered_map<string,string> students;
    for(int i=0;i<n;i++){
        string code,name;cin>>code>>name;
        students[code]=name;
    }
    cin>>m;
    unordered_map <string,ll> freq;
    while(m--){
        ll k;cin>>k;
        for(int i=0;i<k;i++){
            string code;cin>>code;
            freq[code]++;
        }
    }
    set<ll>nums;
    for(auto it:freq){
        nums.insert(it.second);
    }
    ll max=0;
    if (nums.size()>0){
        max = *nums.rbegin();
    }
    multiset<string>names;
    for(auto it:freq){
        if(it.second==max){
            names.insert(students[it.first]);
        }
    }

    if(max==0){
        cout<<"Something is very wrong"<<endl;
        return 0;
    }
    for (auto it:names){
        cout<<it<<"\n";
    }

}