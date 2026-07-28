#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<n; i++) if(a[i] == '1') cnt1++;
    for(int i=0; i<n; i++) if(b[i] == '1') cnt2++;
    if(cnt1 != cnt2){
        cout << -1 << endl;
        return;
    }
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i < n && j < n){
        while(i < n && a[i] != '1') i++;
        while(j < n && b[j] != '1') j++;
        if(i == n) break;
        if(i != j){
            ans++;
        }
        i++;
        j++;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}