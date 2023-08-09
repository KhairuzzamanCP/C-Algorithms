#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    // step 1: actions just after entering a node u
    visited[u] = true;
    cout << "visiting node:" << u << endl;
    for (int v : adj[u])
    {
        // setp 2: actions before entering a  new neighber
        if (visited[v] == true)
            continue;
        dfs(v);
        // setp 3: actions before exiting a neighber
    }

    // setp 3: actions after exiting a neighber
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        int w;
        cin >> u >> v;
        // cin >> w;
        //   Dircted
        adj[u].push_back(v);
        // UnDircted
        adj[v].push_back(u);
    }
    /*  for (int i = 1; i <= n; i++)
     {
         cout << "Node " << i << ":";
         for (int j : adj[i])
         {
             cout << j << " ";
         }
         cout << endl;
     } */
    dfs(1);
    return 0;
}
