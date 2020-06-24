    /// Verdict: AC
    
    #include <iostream>
    #include <cstring>
    #include <cstdlib>
    using namespace std;
     
    int main()
    {
        int tc, i, ara[101], a1, a2, temp, j, k, n, m, l, a, b;
        char op;
     
        cin >> tc;
        for(i=0; i<tc; i++) {
            cin >> n >> m;
            for(j=0; j<n; j++) {
                cin >> ara[j];
            }
            for(k=0; k<m; k++) {
                cin >> op;
                if(op == 'R') {
                    for(l=0; l<n/2; l++) {
                        temp = ara[l];
                        ara[l] = ara[n-l-1];
                        ara[n-l-1] = temp;
                    }
                }
                else if(op == 'P') {
                    cin >> a >> b;
                    temp = ara[a];
                    ara[a] = ara[b];
                    ara[b] = temp;
                }
                else if(op == 'S') {
                    cin >> a;
                    for(l=0; l<n; l++) {
                        ara[l] += a;
                    }
                }
                else if(op == 'M') {
                    cin >> a;
                    for(l=0; l<n; l++) {
                        ara[l] *= a;
                    }
                }
                else if(op == 'D') {
                    cin >> a;
                    for(l=0; l<n; l++) {
                        ara[l] /= a;
                    }
                }
            }
            cout << "Case " << i+1 << ":" << "\n";
            for(j=0; j<n; j++) {
                cout << ara[j];
                if(j != n-1) cout << ' ';
            }
            cout << "\n";
        }
     
        return 0;
    }
     
