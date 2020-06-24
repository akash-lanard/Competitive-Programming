/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++) {
        stack<string> F, B;
        string cur = "http://www.lightoj.com/";
        printf("Case %d:\n", i+1);
        while(1) {
            string com;
            cin >> com;
            if(com=="QUIT") break;
            else if(com=="VISIT") {
                string url;
                cin >> url;
                B.push(cur);
                cur = url;
                while(!F.empty()) {
                    F.pop();
                }
                cout << cur << endl;
            }
            else if(com=="BACK") {
                if(B.size()==0) {
                    cout << "Ignored" << endl;
                }
                else {
                    F.push(cur);
                    cur = B.top();
                    B.pop();
                    cout << cur << endl;
                }
            }
            else if(com=="FORWARD") {
                if(F.size()==0) {
                    cout << "Ignored" << endl;
                }
                else {
                    B.push(cur);
                    cur = F.top();
                    F.pop();
                    cout << cur << endl;
                }
            }
        }
    }
    return 0;
}
