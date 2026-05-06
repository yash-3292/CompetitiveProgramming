#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(vector<int>& a, vector<int>& b){
    int n = a.size();
    ll ans = 0;
    for(int k=0; k<n; k++){
        int i = 0;
        int j  = k;
        int flag = 1;
        while(i < n){
            if(a[i] >= b[j]){
                flag = 0;
                break;
            }
            i++;
            j = (j+1)%n;
        }
        if(flag) ans++;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++) cin >> c[i];
        ll cnt1 = f(a, b);
        ll cnt2 = f(b, c);
        ll ans = (ll)n * cnt1 * cnt2;
        cout << ans << endl; 
    }
    return 0;
}