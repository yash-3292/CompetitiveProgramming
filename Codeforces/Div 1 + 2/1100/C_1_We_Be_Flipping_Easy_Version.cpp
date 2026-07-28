#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> ans;
    int k = 1;
    for(int i=n-1; i>=0; i--){
        int val = k * arr[i];
        if(val > 0){
            ans.push_back(i+1);
            k = -1*k;
        }
    }
    cout << ans.size() << endl;
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