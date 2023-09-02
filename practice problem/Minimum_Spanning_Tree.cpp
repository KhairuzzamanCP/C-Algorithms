#include <bits/stdc++.h>
#define pi pair<long long int, long long int>
using namespace std;
const long long int N = 1e5 + 5;
vector<pi> v[N];
bool vis[N];
class Edge
{
public:
    long long int a, b, w;
    Edge(long long int a, long long int b, long long int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};
void prims(long long int s)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(s, s, 0));
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        long long int a = parent.a;
        long long int b = parent.b;
        long long int w = parent.w;
        if (vis[b])
            continue;
        vis[b] = true;
        edgeList.push_back(parent);
        for (long long int i = 0; i < v[b].size(); i++)
        {
            pi child = v[b][i];
            if (!vis[child.first])
            {
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }
    edgeList.erase(edgeList.begin());
    long long int sum = 0;
    for (Edge val : edgeList)
    {
        sum += val.w;
    }
    cout << sum << endl;
}
int main()
{
    long long int n, e;
    cin >> n >> e;
    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    prims(1);
    return 0;
}