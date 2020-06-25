/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
vector<int> bin;
 
void binary(int num)
{
    int rem;
 
    if (num <= 1)
    {
        //cout << num;
        bin.push_back(num);
        return;
    }
    rem = num % 2;
    binary(num / 2);
    //cout << rem;
    bin.push_back(rem);
}
 
int main()
{
    int tc, i, j, k, n, flag, p2, sum;
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        bin.clear();
        binary(n);
        /*for(j=0; j<bin.size(); j++) {
            cout << bin[j] << ' ';
        }
        cout << endl;*/
        flag = 0;
        for(j=bin.size()-1; j>=0; j--) {
            if(flag==0 && bin[j]==1) flag = 1;
            else if(flag==1 && bin[j]==0) {
                flag = 2;
                swap(bin[j], bin[j+1]);
                sort(bin.begin()+j+1, bin.end());
            }
        }
        if(flag!=2) {
            if(bin.size()==1) bin.push_back(0);
            else {
                bin.insert(bin.begin()+1, 0);
                sort(bin.begin()+2, bin.end());
            }
        }
 
 
        p2 = 1, sum=0;
        for(j=bin.size()-1; j>=0; j--) {
            sum += bin[j]*p2;
            p2 *= 2;
        }
 
        printf("Case %d: %d\n", i+1, sum);
    }
    return 0;
}
