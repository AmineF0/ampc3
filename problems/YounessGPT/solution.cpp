#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct node{
    string name;
    ll mx=0;
    char c;
    map<char,node*> children;
};

void insert(node* root,string s,ll mx){
    node* cur=root;
    for(ll i=0;i<s.size();i++){
        if(cur->children.find(s[i])==cur->children.end()){
            cur->children[s[i]]=new node();
            cur->children[s[i]]->c=s[i];
            cur->children[s[i]]->mx=mx;
            cur->children[s[i]]->name=s;
        }
        cur=cur->children[s[i]];
        if(cur->mx<mx){
            cur->mx=mx;
            cur->name=s;
        }
        if(cur->mx==mx){
            if(cur->name>s){
                cur->name=s;
            }
        }
    }
}

string search(node* root,string s){
    node* cur=root;
    for(ll i=0;i<s.size();i++){
        if(cur->children.find(s[i])==cur->children.end()){
            return "";
        }
        cur=cur->children[s[i]];
    }
    return cur->name;
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        map<string,ll> mp;
        for(int i=0;i<n;i++){
            string s;cin>>s;
            mp[s]++;
        }
        node* root=new node();
        for(auto it:mp){
            insert(root,it.first,it.second);
        }
        ll q;cin>>q;
        while(q--){
            string s;cin>>s;
            cout<<search(root,s)<<endl;
        }
    }
}