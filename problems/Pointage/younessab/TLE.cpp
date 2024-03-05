#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll m,n;cin>>n;
    vector<pair<string,string>> students;
    for(int i=0;i<n;i++){
        string code,name;cin>>code>>name;
        students.push_back({code,name});
    }
    cin>>m;
    map <string,ll> freq;
    while(m--){
        ll k;cin>>k;
        for(int i=0;i<k;i++){
            string code;cin>>code;
            freq[code]++;
        }
    }
    ll mx =0;
    for(auto it:freq){
        mx = max(mx,it.second);
    }
    vector<string>names;
    for(auto it:freq){
        if(it.second==mx){
            for(auto it2:students){
                if(it2.first==it.first){
                    names.push_back(it2.second);
                }
            }
        }
    }
    if(mx==0){
        cout<<"Something is very wrong"<<endl;
        return 0;
    }
    sort(names.begin(),names.end());
    for (auto it:names){
        cout<<it<<endl;
    }


}