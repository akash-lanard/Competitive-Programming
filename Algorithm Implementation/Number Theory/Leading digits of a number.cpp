#include <bits/stdc++.h>
using namespace std;

//if we need leading digits of n! or n^r
//we can do it in the same method
//or even with different base
int leadDig(int n, int k)
{
    double x = (log(n)/log(10));
    double y = x - (int)x;
    long long res;
    if(y==0.0) res = pow(10, k-1);
    else res = pow(10, y) * pow(10, k-1);
    return res;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    cout << leadDig(n, k) << endl;

    return 0;
}
