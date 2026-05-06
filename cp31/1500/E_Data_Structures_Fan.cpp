#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        string s;
        for(int i=0; i<n; i++) cin >> arr[i];
        cin >> s;
        vector<int> prexor(n);
        prexor[0] = arr[0];
        for(int i=1; i<n; i++) prexor[i] = prexor[i-1]^arr[i];
        int val = 0;
        for(int i=0; i<n; i++) if(s[i] == '1') val ^= arr[i];
        
        int q;
        cin >> q;
        while(q--){
            int tp;
            cin >> tp;
            if(tp == 1){
                int l, r;
                cin >> l >> r;
                l--; r--;
                val ^= prexor[r];
                if(l != 0) val ^= prexor[l-1];
            } else{
                int g;
                cin >> g;
                int ans;
                if(g){
                    ans = val;
                } else{
                    ans = val^prexor[n-1];
                }
                cout << ans << " ";
            }
        }
        cout << endl;
    }
    return 0;
}