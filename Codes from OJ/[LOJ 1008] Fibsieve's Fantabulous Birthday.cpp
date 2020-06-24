/// Verdict: AC

#include <stdio.h>
#include <math.h>

int main()
{
    long long t, i;
    long long l, h, m, a, H;
    scanf("%lld", &t);
    for (i = 0; i < t; i++) {
        scanf("%lld", &a);
        if (a == 1) {
            printf("Case %lld: %d %d\n", i+1, 1, 1);
            continue;
        }
        H = ceil(sqrt(a));
        h = H*H;
        l = (H-1)*(H-1) + 1;
        m = (l+h)/2;
        if (H%2 == 1) {
            if (a >= m) {
                printf("Case %lld: %lld %lld\n", i+1, H - (a-m), H);
            }
            else {
                printf("Case %lld: %lld %lld\n", i+1, H, H - (m-a));
            }
        }
        else {
            if (a >= m) {
                printf("Case %lld: %lld %lld\n", i+1, H, H - (a-m));
            }
            else {
                printf("Case %lld: %lld %lld\n", i+1, H - (m-a), H);
            }
        }
    }
    return 0;
}
