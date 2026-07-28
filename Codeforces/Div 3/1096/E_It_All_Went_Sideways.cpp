#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> sufMin(n);
    sufMin[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) sufMin[i] = min(sufMin[i+1], arr[i]);
    ll ans = 0;
    for(int i=0; i<n; i++) ans += (ll)(arr[i] - sufMin[i]);
    stack<int> st;
    int maxi = 0;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        int pse = st.empty() ? -1 : st.top();
        st.push(i);
        if(arr[i] == sufMin[i]) maxi = max(maxi, i-pse-1);
    }
    ans += (ll)maxi;
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}