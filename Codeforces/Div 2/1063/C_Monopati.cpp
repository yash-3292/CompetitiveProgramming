#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a1(n), a2(n);
        for(int i=0; i<n; i++) cin >> a1[i];
        for(int i=0; i<n; i++) cin >> a2[i];
        vector<int> premin(n);
        vector<int> premax(n);
        vector<int> sufmin(n);
        vector<int> sufmax(n);
        premin[0] = a1[0];
        for(int i=1; i<n; i++){
            premin[i] = min(premin[i-1], a1[i]);
        }
        premax[0] = a1[0];
        for(int i=1; i<n; i++){
            premax[i] = max(premax[i-1], a1[i]);
        }
        sufmin[n-1] = a2[n-1];
        for(int i=n-2; i>=0; i--){
            sufmin[i] = min(sufmin[i+1], a2[i]);
        }
        sufmax[n-1] = a2[n-1];
        for(int i=n-2; i>=0; i--){
            sufmax[i] = max(sufmax[i+1], a2[i]);
        }
        vector<int> ans(2*n+1, 0);
        for(int i=0; i<n; i++){
            int l = min(premin[i], sufmin[i]);
            int r = max(premax[i], sufmax[i]);
            ans[l] = max(ans[l], 2*n-r+1);
            // cout << l << " " << r << endl;
        }
        ll sum = 0;
        int val = 0;
        for(int i=2*n; i>=1; i--){
            val = max(val, ans[i]);
            sum += (ll)val;
        }
        cout << sum << endl;
        // cout << endl;
    }
    return 0;
}