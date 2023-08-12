// Question : You will be given an undirected graph as input.This graph will contain only one connected component.The edge number will be exactly node - 1. Then take a node from the input and print its depth.Consider root as 1.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 4;
vector<int> adjList[N];
bool visited[N];
int height[N];

void dfs(int root)
{
    visited[root] = true;
    for (auto child : adjList[root])
    {
        if (visited[child])
            continue;

        dfs(child);
        height[root] = max(height[root], height[child] + 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int root = 1;
    int target;
    cin >> target;
    dfs(root);

    cout << "Height of " << target << " is -> " << height[target] << endl;

    return 0;
}