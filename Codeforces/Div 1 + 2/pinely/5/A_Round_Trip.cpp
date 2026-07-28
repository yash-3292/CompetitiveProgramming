#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int r0, x, d, n;
    cin >> r0 >> x >> d >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            cnt++;
            r0 = max(0, r0-d);
        } else{
            if(r0 >= x) continue;
            cnt++;
            r0 = max(0, r0-d);
        }
    }
    cout << cnt << endl;
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