#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, x;
    cin >> n >> x;
    if(x == 0){
        if(n == 1){
            cout << -1 << endl;
        } else{
            if(n&1){
                cout << n+3 << endl;
            } else{
                cout << n << endl;
            }
        }
        return;
    }
    if(x == 1){
        if(n&1){
            cout << n << endl;
        } else{
            cout << n+3 << endl;
        }
        return;
    }
    int cnt = 0;
    int temp = x;
    while(temp > 0){
        temp = (temp & (temp-1));
        cnt++;
    }
    int ans = x;
    if(cnt < n){
        int left = n - cnt;
        if(left&1){
            ans++;
        }
        ans += left;
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