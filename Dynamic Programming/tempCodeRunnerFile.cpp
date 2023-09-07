
    li ans1 = fibo(n - 1);
    li ans2 = fibo(n - 2);
    save[n] = ans1 + ans2;
    return save[n];