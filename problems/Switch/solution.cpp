  #include <bits/stdc++.h>
  using namespace std;

  pair<bool, int> isBroken(vector<int> &color, vector<vector<int>> &g, int u, vector<int> &vis){
    
    if( color[u] == 1 ) return {true, u};
    if( color[u] == 0 ) return {false, -1};
    
    vis[u]=-2;
    
    
    bool broken = true;

    int indBroken = -1;

    for(int v : g[u]){
      if(vis[v] == -2) continue;
      auto [b, w] = isBroken(color, g, v, vis);
      if( w != -1 ) indBroken = w;
      
      if(b==0) broken = false;
    }

    color[u] = broken ? 1 : 0;
    vis[u] = indBroken;
    
    if( broken ) return {true, u};
    return {false, indBroken};
  }

  int main(){
    int p; cin >> p;
    int sc = p-2;

    int n = p+sc+2;
    // AI : 0
    // switches : 1 to sc
    // lights : sc+1 to p+sc

    vector<vector<int>> g(p+sc+2);

    for(int i=0; i< 2*(sc+1); i++){
      string a, b; long long a0, b0;
      cin >> a >> a0 >> b >> b0;
      if( a == "a" ) a0 = 0;
      else if ( a == "s" ) a0 = a0 + 1;
      else a0 = a0 + sc +1;

      if( b == "a" ) b0 = 0;
      else if ( b == "s" ) b0 = b0 +1;
      else b0 = b0 + sc + 1;

      g[a0].push_back(b0);
      g[b0].push_back(a0);
    }

    vector<int> color(n, -1);
    vector<int> vis(n, 0);

    int k; cin >>k;
    
    for(int i=0; i<n; i++){
      color[sc+i+1] = 0;
    }

    for(int i=0; i<k; i++){
      int a; cin >> a;
      color[a+sc+1] = 1;
    }

    pair<bool, int> ans = isBroken(color, g, 0, vis);
  
    int v = ans.second;
  
    if(v == 0) cout << "AGI is myth" << endl;
    else cout << v-1 << endl;

    return 0;
  }