#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        int one1 = 0;
        int one2 = 0;
        for(int i=0; i<n; i++){
            if(s1[i] == '1') one1++;
        }
        for(int i=0; i<n; i++){
            if(s2[i] == '1') one2++;
        }
        if(one1+one2 < n+1){
            cout << -1 << endl;
            continue;
        }
        vector<ll> a(one1+1);
        vector<ll> b(one2+1);
        a[0] = 0;
        b[0] = 0;
        int cnt = 1;
        int zero = 0;
        for(int i=0; i<n; i++){
            if(s1[i] == '1'){
                a[cnt] = a[cnt-1] + (ll)zero;
                cnt++;
            } else{
                zero++;
            }
        }
        cnt = 1;
        zero = 0;
        for(int i=n-1; i>=0; i--){
            if(s2[i] == '1'){
                b[cnt] = b[cnt-1] + (ll)zero;
                cnt++;
            } else{
                zero++;
            }
        }
        ll mini = 1e18;
        for(int i=1; i<=n; i++){
            if(i <= one1){
                if(n+1-i <= one2){
                    mini = min(mini, a[i]+b[n+1-i]);
                }
            }
        }
        cout << mini << endl;
    }
    return 0;
}