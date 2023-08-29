for (int u = 0; u <= n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.first;
                int w = vpair.second;
                if (d[u] != INF && d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                }
            }
        }