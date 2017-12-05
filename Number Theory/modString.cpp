#include <bits/stdc++.h>
using namespace std;

int modString(string num, int m)
{
    int res = 0;
    for(int i=0; i<num.size(); i++) {
        res = (res*10 + (int)num[i] - '0') % m;
    }
    return res;
}

int main()
{
    while(1) {
        string str;
        cin >> str;
        if(str=="0") break;
        int ans = modString(str, 17);
        cout << ans << endl;
    }
    return 0;
}
