#include <bits/stdc++.h>
using namespace std;

int isleap(int y)
{
    return y%4==0 && (y%100 != 0 || y%400 == 0);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", isleap(n));
    return 0;
}
