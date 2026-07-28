#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            arr.push_back(i);
            if(i != n/i) arr.push_back(n/i);
        }
    }
    sort(arr.begin(), arr.end());
    arr.pop_back();
    for(auto it: arr){
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<n; i++){
            int idx1 = i%it;
            int idx2 = idx1 + n - it;
            if(s[i] != s[idx1]) cnt1++;
            if(s[i] != s[idx2]) cnt2++;
        }
        if(cnt1 <= 1 || cnt2 <= 1){
            cout << it << endl;
            return;
        }
    }
    cout << n << endl;
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