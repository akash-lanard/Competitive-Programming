/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //double ara[1000000];
    vector<double> ara;
    double d;
    int cnt, i;

    cnt = 0;
    for(i=0; scanf("%lf", &d) != EOF; i++) {
        ara.push_back(d);
        cnt++;
    }

    for(i=ara.size()-1; i>=0; i--) {
        printf("%0.4lf\n", sqrt(ara[i]));
    }

    return 0;
}
