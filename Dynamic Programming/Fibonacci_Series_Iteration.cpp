#include <bits/stdc++.h>
using namespace std;
#define li long long
int main()
{
    li n;
    cin >> n;
    li a[n + 1];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << endl;
    return 0;
}
