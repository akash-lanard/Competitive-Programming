/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        int x;
        scanf("%d", &x);
        vector<int>::iterator low, up;
        low = lower_bound(v.begin(), v.end(), x);
        up = upper_bound(v.begin(), v.end(), x);

        if(low==v.begin() && up==v.end()) printf("X X\n");
        else if(low==v.begin() && up!=v.end()) printf("X %d\n", *up);
        else if(low!=v.begin() && up==v.end()) printf("%d X\n", *(low-1));
        else printf("%d %d\n", *(low-1), *up);
    }
    return 0;
}
