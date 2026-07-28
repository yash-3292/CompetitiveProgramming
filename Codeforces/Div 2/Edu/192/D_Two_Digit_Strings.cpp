#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int cnt1 = 0, cnt2 = 0;
    for(auto ch : a) cnt1 += ch - '0';
    for(auto ch : b) cnt2 += ch - '0';
    if(cnt1%10 != cnt2%10){
        cout << -1 << endl;
        return;
    }
    vector<int> arr1(n, 0), arr2(m, 0);
    for(int i=0; i<n; i++){
        arr1[i] = a[i]-'0';
        if(i > 0) arr1[i] += arr1[i-1];
        arr1[i] = arr1[i]%10;
    }
    for(int i=0; i<m; i++){
        arr2[i] = b[i]-'0';
        if(i > 0) arr2[i] += arr2[i-1];
        arr2[i] = arr2[i]%10;
    }
    vector<int> prev(m+1, 0);
    vector<int> cur(m+1);
    for(int i=1; i<=n; i++){
        cur[0] = 0;
        for(int j=1; j<=m; j++){
            int ans = 0;
            if(arr1[i-1] == arr2[j-1]){
                ans = 1 + prev[j-1];
            } else{
                ans = max(prev[j], cur[j-1]);
            }
            cur[j] = ans;
        }
        prev = cur;
    }
    int ans = prev[m];
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