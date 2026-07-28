#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    vector<int> val;
    for(int i=k; i>=1; i--){
        val.push_back(i);
    }
    // for(auto it : val) cout << it << " ";
    // cout << endl;
    for(int i=0; i<k; i++){
        int m = i % (2*n);
        m = min(m, 2*n-1-m);
        // cout << m << " ";
        // cout << val[i] << " ";
        arr[m] += val[i];
    }
    int maxi = 0;
    for(auto it : arr) maxi = max(maxi, it);
    cout << maxi << endl;
    // cout << endl;
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