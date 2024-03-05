#include <bits/stdc++.h>
using namespace std;

int main(){

  int n; cin >> n;
  map<string, string> names;
  for(int i = 0; i < n; i++){
    string name, score;
    cin >> name >> score;
    names[name] = score;
  }

  map<string, long long> attendance;
  int m; cin >> m;
  
  long long mx = 0;

  for(int i = 0; i < m; i++){
    string code; cin >> code;
    attendance[names[code]]++;
    mx = max(mx, attendance[names[code]]);
  }

  priority_queue<string, vector<string>, greater<string>> pq;

  for(auto it = attendance.begin(); it != attendance.end(); it++){
    if(it->second == mx){
      pq.push(it->first);
    }
  }

  if(pq.size() == 0){
    cout << "" << endl;
  } else {
    while(pq.size() > 1){
      cout << pq.top() << "\n";
      pq.pop();
    }
  }

  return 0;
}