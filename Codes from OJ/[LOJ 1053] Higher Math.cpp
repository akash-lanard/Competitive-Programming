/// Verdict: AC

#include <iostream>
using namespace std;
 
int main()
{
    int tc, a, b,c, temp, i;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> a >> b >> c;
        if(a >= b && a >= c) {
            temp = a;
            a = c;
            c = temp;
        }
        else if(b >= a && b >= c) {
            temp = b;
            b = c;
            c = temp;
        }
        if(c*c == (a*a + b*b)) {
            cout << "Case " << i+1 << ": " << "yes" << "\n";
        }
        else {
            cout << "Case " << i+1 << ": " << "no" << "\n";
        }
    }
 
    return 0;
}
