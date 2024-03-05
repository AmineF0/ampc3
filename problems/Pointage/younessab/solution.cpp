#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll m,n;cin>>n>>m;
    map<string,string> students;
    for(int i=0;i<n;i++){
        string code,name;cin>>code>>name;
        students[code]=name;
    }
    map <string,ll> freq;
    while(m--){
        ll k;cin>>k;
        for(int i=0;i<k;i++){
            string code;cin>>code;
            freq[code]++;
        }
    }
    vector<ll>nums;
    for(auto it:freq){
        nums.push_back(it.second);
    }
    sort(nums.begin(),nums.end());
    ll max = nums[nums.size()-1];
    vector<string>names;
    for(auto it:freq){
        if(it.second==max){
            names.push_back(students[it.first]);
        }
    }
    if(names.size()==0){
        cout<<"Something is very wrong"<<endl;
    }
    for(auto it:names){
        cout<<it<<endl;
    }

}