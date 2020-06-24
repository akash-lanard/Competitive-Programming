/// Verdict: WA
/// DON'T USE FLOAT

#include <stdio.h>
#include <math.h>

#define pi 2*acos(0.0)

int main()
{
    int t, i;
    float r, a, b, c;

    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        scanf("%f", &r);
        a = (4*r*r) - (pi*r*r) + 10e-8;

        printf("Case %d: %0.2f\n", i, a);
    }
    return 0;
}
