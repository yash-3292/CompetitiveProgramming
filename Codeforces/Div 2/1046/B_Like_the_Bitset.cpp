#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0') cnt = 0;
        else cnt++;
        if(cnt >= k){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    vector<int> ans(n);
    cnt = n;
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            ans[i] = cnt--;
        }
    }
    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            ans[i] = cnt--;
        }
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
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