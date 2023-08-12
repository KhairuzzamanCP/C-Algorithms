// Question : You will be given a directed graph as input.Store this graph in an adjacency list.Now, convert this adjacency list to an adjacency matrix(index starting from 1) and print it.Consider root as 1.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
int adjMat[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto val : adjList[i])
        {
            adjMat[i][val] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}