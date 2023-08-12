/*  You will be given an adjacency matrix for a directed graph (index starting from 1) as input. Now, convert it to an adjacency list and print it. */

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int adjMat[N][N];
vector<int> adjList[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            int m;
            cin >> m;
            if (m == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for (auto val : adjList[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}