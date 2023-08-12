#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << "visiting Node: " << u << endl;
        // setp 1: node ke u thake ber kora
        for (int v : adj[u])
        {
            // step 2: child ar kaj soro korar age
            if (visited[v] == true)
                continue;
            // step 2: child ar kaj soro korar pore
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
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
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "level of " << i << " : " << level[i] << endl;
    }
    return 0;
}
