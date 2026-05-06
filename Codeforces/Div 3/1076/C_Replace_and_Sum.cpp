#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            cin >> b[i];
            a[i] = max(a[i], b[i]);
        } 
        for(int i=n-2; i>=0; i--){
            a[i] = max(a[i], a[i+1]);
        }
        for(int i=1; i<n; i++){
            a[i] += a[i-1];
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            l--; r--;
            int ans = a[r];
            if(l > 0) ans -= a[l-1];
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}