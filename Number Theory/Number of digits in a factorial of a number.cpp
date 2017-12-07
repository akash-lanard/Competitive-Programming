#include <bits/stdc++.h>
using namespace std;

double cumsum[10000010];

void f()
{
    cumsum[0] = 0.0;
    double sum = 0.0;
    for(int i=1; i<10000010; i++) {
        sum += log(i);
        cumsum[i] = sum;
    }
}

int main()
{
    f();
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        int n;
        scanf("%d", &n);
        int ans = cumsum[n]/log(10) + 1;
        printf("%d\n", ans);
    }
    return 0;
}
