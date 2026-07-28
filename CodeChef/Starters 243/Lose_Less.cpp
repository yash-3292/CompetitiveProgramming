#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int m, n;
    cin >> m >> n;
    int mini = INT_MAX;
    for(int i=0; i<=m; i++){
        int val = i*3;
        if(val > n) break;
        int single = n - val;
        if(single + i > m){
            continue;
        }
        int ans = m - (single + i);
        // cout << i << " " << ans << endl;
        mini = min(mini, ans); 
    }
    cout << mini << endl;
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