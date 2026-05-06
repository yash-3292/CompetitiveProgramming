#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;
        int val1 = (rk < rd) ? (rd) : (n-rd);
        if(rk == rd) val1 = min(val1, abs(ck-cd));
        int val2 = (ck < cd) ? (cd) : (n-cd);
        if(ck == cd) val2 = min(val2, abs(rk-rd));
        int ans = max(val1, val2);
        cout << ans << endl;
    }
    return 0;
}