#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> g;
int visited[N][N];
int level[N][N];  // ekhane lagbe na amader
pii parent[N][N]; // path track kortechi
int n, m;
vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // moves, left, right, up, down

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m); // cell ta ke access kora jabe kina kina, wall thakle false dibe
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj}); // source er row ar column ke store korlam
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : direc) // moves,
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#') // jodi wall na thake
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j}; // path track korlam
            }
        }
    }
}

int main()
{

    int si, sj, di, dj;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;                   // string input
        for (int j = 0; j < m; j++) // column er upor loop cholteche
        {
            if (x[j] == 'A')    //
                si = i, sj = j; // source er row ar column ke track korlam
            if (x[j] == 'B')
                di = i, dj = j; // // destination er row ar column ke track korlam
        }
        g.push_back(x);
    }

    bfs(si, sj);            // source theke bfs chalacchi
    if (level[di][dj] != 0) // destination er level jodi 0 na hoy tar mane seta source er soman na
    {
        cout << "YES\n";
        cout << level[di][dj] << endl;
        vector<pii> path;
        pii curr = {di, dj}; // ami source theke bfs korte korte destination obdi chole aschi

        while (!(curr.first == si && curr.second == sj)) // destination er parent er parent e jaitei thakbo jotokkhn na obdi ami source ke pacchi
        {
            path.push_back(curr); // protita path ke ami store korlam
            curr = parent[curr.first][curr.second];
        }
        path.push_back({si, sj});          // amra destination theke source er ag obdi aschi tai amra source er path keo push korlam print korar jonne
        reverse(path.begin(), path.end()); //

        for (int i = 1; i < path.size(); i++)
        {
            // path[i-1] -> path[i]
            if (path[i - 1].first == path[i].first)
            {
                if (path[i - 1].second == path[i].second - 1)
                    cout << "R";
                else
                    cout << "L";
            }
            else
            {
                if (path[i - 1].first == path[i].first - 1)
                    cout << "D";
                else
                    cout << "U";
            }
        }
    }
    else
        cout << "NO\n";
    return 0;
}