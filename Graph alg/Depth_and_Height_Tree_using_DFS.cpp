#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    // step 1: actions just after entering a node u
    visited[u] = true;
    // cout << "visiting node:" << u << endl;
    for (int v : adj[u])
    {
        // setp 2: actions before entering a  new neighber
        if (visited[v] == true)
            continue;
        // depth count
        depth[v] = depth[u] + 1;
        dfs(v);
        // setp 3: actions before exiting a neighber
        // height count

        // if (height[v] + 1 > height[u])
        //     height[u] = height[v] + 1;
        height[u] = max(height[u], height[v] + 1);
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

    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Depth of Node " << i << ": " << depth[i] << endl;
    }
    cout << "---------------------------\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "height of Node " << i << ": " << height[i] << endl;
    }
    return 0;
}
