#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> l(n), r(n), ans(n, 0);
        for(ll i=0; i<n; i++) cin >> l[i] >> r[i];
        vector<vector<ll>> arr1, arr2;
        for(ll i=0; i<n; i++){
            arr1.push_back({l[i], r[i], i});
            arr2.push_back({r[i], l[i], i});
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        multiset<ll> st;
        ll j = 0;
        for(ll i=0; i<n; i++){
            while(j < n && arr1[j][0] <= arr1[i][0]){
                st.insert(arr1[j][1]);
                j++;
            }
            ll val;
            auto it = st.lower_bound(arr1[i][1]);
            it++;
            if(it != st.end()){
                val = *it - arr1[i][1];
                ans[arr1[i][2]] += val;
            }
        }
        st.clear();
        j = n-1;
        for(ll i=n-1; i>=0; i--){
            while(j >= 0 && arr2[j][0] >= arr2[i][0]){
                st.insert(arr2[j][1]);
                j--;
            }
            ll val;
            auto it = st.upper_bound(arr2[i][1]);
            it--;
            if(it != st.begin()){
                it--;
                val = arr2[i][1] - *it;
                ans[arr2[i][2]] += val;
            }
        }
        for(ll i=0; i<n; i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}