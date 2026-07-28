#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    unordered_map<int,int> vis;
    int mexx = 0;
    unordered_map<int, int> freq;
    for(int i=0; i<n; i++){
        vis[arr[i]] = 1;
        while(vis.find(mexx) != vis.end()) mexx++;
        freq[arr[i]]++;
    }
    vector<int> ans(n+2,0);
    for(int i=0; i<=mexx; i++){
        int l = freq[i];
        int r = n-i;
        ans[l]++;
        ans[r+1]--;
    }
    for(int i=1; i<=n+1; i++) ans[i] += ans[i-1];
    for(int i=0; i<=n; i++) cout << ans[i] << " ";
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