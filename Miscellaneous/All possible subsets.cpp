#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p[20], N=20;
    for(int i=0; i<N; i++) p[i] = i;

    for(int i=0; i < (1<<N); i++) {
        for(int j=0; j<N; j++) {
            if(i &(1<<j)) {
                printf("%d ", p[j]);
            }
        }
        printf("\n");
        system("PAUSE");
    }
    return 0;
}
