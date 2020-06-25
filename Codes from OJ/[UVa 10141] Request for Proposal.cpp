/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

struct data {
    string name;
    int metreq;
    double price;
    int indx;
};

bool comp(data& a, data& b)
{
    if(a.metreq>b.metreq) return true;
    else if(a.metreq<b.metreq) return false;
    else if(a.price<b.price) return true;
    else if(a.price>b.price) return false;
    else if(a.indx<b.indx) return true;
    else return false;
}
int main()
{
    for(int i=0; ;i++) {
        int n, p;
        scanf("%d %d", &n, &p);
        if(n==0 && p==0) break;
        struct data prop[p];
        cin.ignore();
        for(int j=0; j<n; j++) {
            string temp1;
            getline(cin, temp1);
        }
        for(int j=0; j<p; j++) {
            string str;
            int N;
            double pr;
            getline(cin, str);
            scanf("%lf %d", &pr, &N);

            prop[j].name = str;
            prop[j].metreq = N;
            prop[j].price = pr;
            prop[j].indx = j;

            cin.ignore();
            for(int k=0; k<N; k++) {
                string temp2;
                getline(cin, temp2);
            }
        }
        sort(prop, prop+p, comp);
        if(i!=0) printf("\n");
        printf("RFP #%d\n", i+1);
        cout << prop[0].name << endl;
    }
    return 0;
}
