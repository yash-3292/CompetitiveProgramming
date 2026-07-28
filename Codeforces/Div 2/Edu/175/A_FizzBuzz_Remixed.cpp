#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    if(n%15 == 0){
        ans++;
    } else if(n%15 == 1){
        ans += 2;
        n--;
    } else if(n%15 == 2){
        ans += 3;
        n -= 2;
    } else{
        n += 15 - n%15;
    }
    ans += (n/15) * 3;
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