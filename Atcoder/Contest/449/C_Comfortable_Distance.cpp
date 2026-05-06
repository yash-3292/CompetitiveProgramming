#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x, string& s){
    map<char,int> freq;
    ll ans = 0;
    ll n = s.size();
    ll l = 0;
    ll r = 0;
    while(r < n){
        freq[s[r]]++;
        if(r-l > x){
            freq[s[l]]--;
            l++;
        }
        ans += freq[s[r]] - 1;
        r++;
    }
    return ans;
}

int main(){
    ll n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    ll ans = f(r, s);
    if(l > 1) ans -= f(l-1, s);
    cout << ans << endl;
    return 0;
}