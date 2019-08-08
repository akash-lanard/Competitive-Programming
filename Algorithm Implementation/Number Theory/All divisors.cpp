#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000002

vector<int> divisors[SIZE]; // divisors of i

// calculates of divisors of 1 to n
// time complexity is nlogn
void Divisors(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            divisors[j].push_back(i);
        }
    }
}

int main() {
    int n;
    cin >> n;

    Divisors(n);

    for(int i=1; i<=n; i++) {
        printf("Divisors of %d:", i);
        for(int j=0; j<divisors[i].size(); j++) {
            printf(" %d", divisors[i][j]);
        }
        printf("\n");
    }
    return 0;
}
