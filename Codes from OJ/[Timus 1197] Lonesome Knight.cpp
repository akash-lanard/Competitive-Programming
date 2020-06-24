/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, i, j, r, c, ans;
    char x;

    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> x >> c;
        if(x=='a') r = 1;
        else if(x=='b') r = 2;
        else if(x=='c') r = 3;
        else if(x=='d') r = 4;
        else if(x=='e') r = 5;
        else if(x=='f') r = 6;
        else if(x=='g') r = 7;
        else if(x=='h') r = 8;

        ans = 0;

        if(((r+2>=1) && (r+2<=8)) && ((c+1>=1) && (c+1<=8))) ans++;
        if(((r+1>=1) && (r+1<=8)) && ((c+2>=1) && (c+2<=8))) ans++;
        if(((r-1>=1) && (r-1<=8)) && ((c+2>=1) && (c+2<=8))) ans++;
        if(((r-2>=1) && (r-2<=8)) && ((c+1>=1) && (c+1<=8))) ans++;
        if(((r-2>=1) && (r-2<=8)) && ((c-1>=1) && (c-1<=8))) ans++;
        if(((r-1>=1) && (r-1<=8)) && ((c-2>=1) && (c-2<=8))) ans++;
        if(((r+1>=1) && (r+1<=8)) && ((c-2>=1) && (c-2<=8))) ans++;
        if(((r+2>=1) && (r+2<=8)) && ((c-1>=1) && (c-1<=8))) ans++;

        cout << ans << endl;
    }

    return 0;
}
