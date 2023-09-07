#include <bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    // base case
    // long cat
    if (n == 0 || n == 1)
        return 1;
    // shot cat
    if (n <= 1)
        return 1;
    // long cat
    int ans1 = fibo(n - 1);
    int ans2 = fibo(n - 2);
    return ans1 + ans2;

    // sort cat

    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << " ";
    return 0;
}
