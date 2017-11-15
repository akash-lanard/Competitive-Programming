#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, -1));  //swap 1 and -1 if ending time
        v.push_back(make_pair(b, 1));   //needs to come first at a specific time
    }
    sort(v.begin(), v.end());

    /*for(int i=0; i<v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }*/

    int LCT=0, LIT=0, cnt=0;
    int ssstart, ssend, flag=0;
    for(int i=0; i<v.size(); i++) {
        if(i==0) {
            ssstart = v[0].first;
            cnt++;
            flag = 1;
        }
        else {
            if(v[i].second==-1) cnt++;
            else if(v[i].second==1) cnt--;
            if(cnt==0 && flag==1) {
                ssend = v[i].first;
                if((ssend-ssstart)>LCT) {
                    LCT = (ssend-ssstart);
                }
                ssstart = v[i].first;
                flag = 0;
            }
            else if(cnt==1 && flag==0) {
                ssend = v[i].first;
                if((ssend-ssstart)>LIT) {
                    LIT = (ssend-ssstart);
                }
                ssstart = v[i].first;
                flag = 1;
            }
        }
    }

    cout << LCT << " " << LIT << endl;

    return 0;
}


