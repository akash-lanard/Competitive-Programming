/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, x, y, z, m;
    vector<int> digits;
    cin >> n;

    if(n==0) cout << 10;
    else if(n==1) cout << 1;
    else {
        m = n;

        for(i=9; i>=2; i--) {
            if(m==1) break;
            while(m%i==0) {
                digits.push_back(i);
                m /= i;
            }
        }

        if(m==1) {
            //if(digits.size()==1) cout << 1;
            for(i=digits.size()-1; i>=0; i--) {
                cout << digits[i];
            }
        }
        else {
            cout << -1;
        }
    }

    return 0;
}
