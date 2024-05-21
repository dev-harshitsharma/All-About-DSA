#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
        return n;
    int last = fibo(n - 1);
    int secondLast = fibo(n - 2);

    return last + secondLast;
}

int main()
{
    cout < "The fourth number of the fibonacci series is  " << fibo(4);
}