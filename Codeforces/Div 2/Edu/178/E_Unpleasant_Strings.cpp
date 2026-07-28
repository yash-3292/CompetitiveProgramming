#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ans(n+2);
    vector<vector<int>> next(n+2);
    vector<int> pos(k, n+1);
    next[n+1] = pos;
    for(int i=n; i>=0; i--){
        next[i] = pos;
        if(i > 0) pos[s[i-1]-'a'] = i;
    }
    ans[n+1] = 0;
    for(int i=n; i>=0; i--){
        int mini = INT_MAX;
        for(int j=0; j<k; j++){
            mini = min(mini, 1+ans[next[i][j]]);
        }
        ans[i] = mini;
    }
    int q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        int x = 0;
        for(auto ch : t){
            x = next[x][ch-'a'];
        }
        cout << ans[x] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}