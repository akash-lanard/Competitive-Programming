#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int ara[n+1];
    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i]);
    }

    printf("Before sort:\n");
    for(int i=1; i<=n; i++) {
        printf("%d ", ara[i]);
    }
    cout << endl;

    //start

    for(int j=2; j<=n; j++) {
        int key = ara[j];
        int i;
        for(i=j-1;i>0 && ara[i]>key; i--) {
            ara[i+1] = ara[i];
        }
        ara[i+1] = key;
    }

    //end

    printf("After sort:\n");
    for(int i=1; i<=n; i++) {
        printf("%d ", ara[i]);
    }
    cout << endl;
    return 0;
}
