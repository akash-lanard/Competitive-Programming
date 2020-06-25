/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

void recur(int cnt, int n)
{
    if(cnt==n-1) {
        printf("sin(%d)", cnt+1);
        for(int i=0; i<cnt; i++) printf(")");
        return;
    }
    printf("sin(");
    cnt++;
    printf("%d", cnt);
    if(cnt%2==0) printf("+");
    else printf("-");
    recur(cnt, n);
}

void f(int i, int n)
{
    if(i==n) {
        recur(0, i);
        printf("+1\n");
        return;
    }
    if(i==1) {
        for(int i=1; i<n; i++) printf("(");
    }
    recur(0, i);
    printf("+%d)", n-i+1);
    f(i+1, n);
}

int main()
{
    int n;
    cin >> n;
    f(1, n);
    return 0;
}
