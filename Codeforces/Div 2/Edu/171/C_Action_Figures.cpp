#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    ll sum = (n * (n+1)) / 2;
    for(ll i=n-1; i>=0; i--){
        if(s[i] == '1'){
            if(cnt+1 > i){
                break;
            }
            cnt++;
            sum -= (i+1);
        } else{
            if(cnt > 0) cnt--;
        }
    }
    cout << sum << endl;
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