#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct node {
  char caracter;
  int mx = -1;
  string word;
  vector<node*> children;
  node(char c){
    children = vector<node*>(26, NULL);
    caracter = c;
  }
  node(char c, int count, string s){
    children = vector<node*>(26, NULL);
    caracter = c;
    mx = count;
    word = s;
  }
} node ;

typedef struct node{
    string name;
    ll mx=0;
    char c;
    map<char,node*> children;
};
void insert(node *root, string s, int count){
  node *cur = root;
  for(int i=0; i<s.size(); i++){
    int c = s[i] - 'a';
    if( cur->children[c] == NULL ){
      cur->children[c] = new node(s[i], count, s);
    }

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
    if( cur->mx < count ) {
      cur->mx = count;
      cur->word = s;  
    }

    cur = cur->children[c];
  }
}

string getWord(node *root, string s){
  node *cur = root;
  for(int i=0; i<s.size(); i++){
    int c = s[i] - 'a';
    if( cur->children[c] == NULL ) return s;
    cur = cur->children[c];
  }
  return cur->word;
}

int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    map<string, int> m;
    for(int i=0; i<n; i++){
      string s; cin >> s;
      m[s]++;;
    }
    
    vector<pair<int, string>> v;
    for(auto [s, c] : m){
      v.push_back({-c, s});
    }
    sort(v.begin(), v.end(), greater<pair<int, string>>());
    reverse(v.begin(), v.end());

string search(node* root,string s){
    node* cur=root;
    for(ll i=0;i<s.size();i++){
        if(cur->children.find(s[i])==cur->children.end()){
            return "";
        }
        cur=cur->children[s[i]];
    }
    return cur->name;
    node *root = new node('#');

    for(auto [c, s] : v){
      int count = -c;

      // cout << s << " " << count << endl;

      insert(root, s, count);
    }

    int q; cin >> q;

    for(int i=0; i<q; i++){
      string s; cin >> s;
      cout << getWord(root, s) << endl;
    }

  }
  return 0;
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