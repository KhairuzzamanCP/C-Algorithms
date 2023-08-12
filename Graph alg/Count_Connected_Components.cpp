#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // setp 1: node ke u thake ber kora
        for (int v : adj[u])
        {
            // step 2: child ar kaj soro korar age
            if (visited[v] == true)
                continue;
            // step 2: child ar kaj soro korar pore
            q.push(v);
            visited[v] = true;

            // setp 1:  visited kora hole node ke u thake ber kora
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        cc++;
    }
    cout << "Number of Connected Components : " << cc << endl;
    return 0;
}
