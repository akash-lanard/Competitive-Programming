/// Verdict: AC

#include <iostream>
#include <cstdlib>
using namespace std;

int compfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int tc, ara[3], i, j;

    cin >> tc;
    for(i=0; i<tc; i++) {
        for(j=0; j<3; j++) {
            cin >> ara[j];
        }
        qsort(ara, 3, sizeof(int), compfunc);
        cout << "Case " << i+1 << ": " << ara[1] << "\n";
    }

    return 0;
}
