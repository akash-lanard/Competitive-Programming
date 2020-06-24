/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)

int main()
{
    int n, i, j, k;
    double r, x[100], y[100], sum;

    cin >> n >> r;
    for(i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    sum = 0.0;
    for(i=0; i<n; i++) {
        if(i==n-1) sum += sqrt(pow(x[i]-x[0], 2) + pow(y[i]-y[0], 2));
        else sum += sqrt(pow(x[i]-x[i+1], 2) + pow(y[i]-y[i+1], 2));
    }

    sum += 2*PI*r;

    printf("%0.2lf", sum);

    return 0;
}
