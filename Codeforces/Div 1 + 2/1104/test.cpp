#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n){
    if(n <= 2) return 0;
    ll odd = (n-1)/2;
    ll ans = odd * n - ((odd+1) * (odd+1) - 1) + odd;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll sum = 0;
    map<int,int> vis;
    vis[0] = 1;
    for(ll i=0; i<n; i++){
        if(s[i] == '0') sum--;
        else sum++;
        ans += vis[sum];
        vis[sum]++;
    }
    cout << ans << endl;
    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(ll i=0; i<n; i++){
        if(s[i] == '0'){
            cnt0++;
            ans += f(cnt1);
            cnt1 = 0;
        } else{
            ans += f(cnt0);
            cnt0 = 0;
            cnt1++;
        }
        if(i > 0 && s[i] == s[i-1]){
            ans += f(cnt2);
            cnt2 = 1;
        } else{
            cnt2++;
        }
    }
    ans += f(cnt0);
    ans += f(cnt1);
    ans += f(cnt2);
    cout << ans << endl;
    ans = (n * (n+1))/2 - ans;
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