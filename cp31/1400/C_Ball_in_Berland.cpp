#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> arrA(k);
        vector<int> arrB(k);
        vector<int> mppa(a+1, 0);
        vector<int> mppb(b+1, 0);
        for(int i=0; i<k; i++) cin >> arrA[i];
        for(int i=0; i<k; i++) cin >> arrB[i];
        for(int i=0; i<k; i++){
            mppa[arrA[i]]++;
            mppb[arrB[i]]++;
        }
        ll ans = 0;
        for(int i=0; i<k; i++){
            ll val = mppa[arrA[i]] + mppb[arrB[i]] - 1;
            ans += (ll)k - val;
        }
        ans /= 2;
        cout << ans << endl;
    }
    return 0;
}