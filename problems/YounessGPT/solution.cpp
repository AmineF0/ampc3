#include<bits/stdc++.h>
using namespace std;

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

void insert(node *root, string s, int count){
  node *cur = root;
  for(int i=0; i<s.size(); i++){
    int c = s[i] - 'a';
    if( cur->children[c] == NULL ){
      cur->children[c] = new node(s[i], count, s);
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