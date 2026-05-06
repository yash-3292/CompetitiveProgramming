#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        set<ll> st;
        for(int i=0; i<n; i++){
            if(arr[i]*arr[i] < (ll)n) st.insert(arr[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(auto it : st){
                ll j1 = i - it*arr[i];
                if(j1 >= 0 && arr[j1] == it) ans++;
                if(arr[i]*arr[i] < (ll)n) continue;
                ll j2 = i + it*arr[i];
                if(j2 < n && arr[j2] == it) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}