#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(){
    ll m,n;cin>>n>>m;
    vector<pair<string,double>> items;
    for(int i=0;i<n;i++){
        string name;double price;cin>>name>>price;
        items.push_back({name,price});
    }
    double total=0;
    for(int i=0;i<m;i++){
        string name;ll q;cin>>name>>q;
        for(auto it:items){
            if(it.first==name){
                total+=it.second*q;
            }
        }
    }
    cout<<total<<endl;
}