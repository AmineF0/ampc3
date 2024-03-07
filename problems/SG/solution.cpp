#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> &parent)
{
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});

  while (!q.empty())
  {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int next : adj[cur])
    {
      if (parent[next] == -1 && capacity[cur][next])
      {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }

  return 0;
}

int maxflow(int s, int t)
{
  int flow = 0;
  vector<int> parent(n);
  int new_flow;

  while (new_flow = bfs(s, t, parent))
  {
    flow += new_flow;
    int cur = t;
    while (cur != s)
    {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return flow;
}

int main()
{
  // int tasks, cpu, time_slots=101 ; cin >> tasks >> cpu;
  // n = 1 + cpu + time_slots + tasks + 1;

  int s, m, p;
  cin >> s >> m >> p;

  vector<int> machine(m, 0);
  for (int i = 0; i < m; i++)
  {
    cin >> machine[i];
  }
  vector<int> teacher(p, 0);
  for (int i = 0; i < p; i++)
  {
    cin >> teacher[i];
  }

  vector<vector<int>> teacher_machine(p, vector<int>(m, 0));

  for (int i = 0; i < p; i++)
  {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
      int a;
      cin >> a;
      teacher_machine[i][a] = 1;
    }
  }

  n = 1 + p + m + 1;

  // graph : source -> machine -> association machine teacher (inf) -> sink

  // source = 0
  // machine = 1 to m
  // association machine teacher = m+1 to m+p
  // sink = m+p+1

  capacity.assign(n, vector<int>(n, 0));
  adj.assign(n, vector<int>());

  for (int i = 0; i < m; i++)
  {
    capacity[0][i + 1] = machine[i];
    adj[0].push_back(i + 1);
    adj[i + 1].push_back(0);
  } // connect source to machine

  // machine to association machine teacher
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < p; j++)
    {
      if (teacher_machine[j][i] == 1)
      {
        capacity[i + 1][m + j + 1] = INF;
        adj[i + 1].push_back(m + j + 1);
        adj[m + j + 1].push_back(i + 1);
      }
    }
  }

  // association machine teacher to sink with teacher[i]
  for (int i = 0; i < p; i++)
  {
    capacity[m + i + 1][m + p + 1] = teacher[i];
    adj[m + i + 1].push_back(m + p + 1);
    adj[m + p + 1].push_back(m + i + 1);
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < p; j++)
    {
      cout << capacity[i + 1][m + j + 1] << " ";
    }
    cout << endl;
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<adj[i].size(); j++){
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  double maxgrp = maxflow(0, n - 1);
  cout << maxgrp << endl;
}