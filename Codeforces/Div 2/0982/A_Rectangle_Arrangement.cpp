#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    int maxh = 0;
    int maxw = 0;
    for(int i=0; i<n; i++){
        int w, h;
        cin >> w >> h;
        maxh = max(maxh, h);
        maxw = max(maxw, w);
    }
    ans = (maxh + maxw) * 2;
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