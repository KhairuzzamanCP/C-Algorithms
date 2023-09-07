#include <bits/stdc++.h>
using namespace std;
#define li long long
const li N = 1e5 + 5;
li save[N];
li fibo(li n)
{
    // base case
    if (n <= 1)
        return 1;
    // Memoization
    if (save[n] != -1)
    {
        return save[n];
    }

    li ans1 = fibo(n - 1);
    li ans2 = fibo(n - 2);
    save[n] = ans1 + ans2;
    return save[n];
}
int main()
{
    li n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        save[i] = -1;
    }
    cout << fibo(n) << " ";
    return 0;
}
