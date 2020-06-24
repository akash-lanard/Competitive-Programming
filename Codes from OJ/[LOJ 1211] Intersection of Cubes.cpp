/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int compfunc1(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int compfunc2(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int tc, i, j, k, n, x1[100], y1[100], z1[100], x2[100], y2[100], z2[100], temp, x, y, z, ans;

    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        for(j=0; j<n; j++) {
            cin >> x1[j] >> y1[j] >> z1[j] >> x2[j] >> y2[j] >> z2[j];
            if(x1[j]>x2[j]) {
                temp = x1[j];
                x1[j] = x2[j];
                x2[j] = temp;
            }
            if(y1[j]>y2[j]) {
                temp = y1[j];
                y1[j] = y2[j];
                y2[j] = temp;
            }
            if(z1[j]>z2[j]) {
                temp = z1[j];
                z1[j] = z2[j];
                z2[j] = temp;
            }
        }
        qsort(x1, n, sizeof(int), compfunc2);
        qsort(y1, n, sizeof(int), compfunc2);
        qsort(z1, n, sizeof(int), compfunc2);

        qsort(x2, n, sizeof(int), compfunc1);
        qsort(y2, n, sizeof(int), compfunc1);
        qsort(z2, n, sizeof(int), compfunc1);

        x = x2[0] - x1[0];
        y = y2[0] - y1[0];
        z = z2[0] - z1[0];
        ans = x*y*z;
        if(ans < 0) ans = 0;

        printf("Case %d: %d\n", i+1, ans);
    }

    return 0;
}
