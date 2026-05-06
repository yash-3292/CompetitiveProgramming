#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int i, string& a, string& b, vector<char>& arr, unordered_map<char,int>& mpp, ll &maxi, int k){
    if(i < 0){
        if(mpp.size() == k){
            int n = a.size();
            ll ans = 0;
            ll cnt = 0;
            for(int j=0; j<n; j++){
                if(a[j] != b[j] && mpp.find(a[j]) == mpp.end()){
                    if(cnt > 0) ans += ((cnt)*(cnt+1))/2;
                    cnt = 0;
                } else{
                    cnt++;
                }
            } 
            if(cnt > 0) ans += ((cnt)*(cnt+1))/2;
            cnt = 0;
            maxi = max(maxi, ans);
        }
        return;
    } 
    f(i-1, a, b, arr, mpp, maxi, k);
    mpp[arr[i]] = 1;
    f(i-1, a, b, arr, mpp, maxi, k);
    mpp.erase(arr[i]);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a;
        cin >> b;
        unordered_set<char> st;
        for(int i=0; i<n; i++){
            if(a[i] != b[i]){
                st.insert(a[i]);
            }
        }
        if(st.size() <= k){
            ll ans = ((ll)(n) * (ll)(n+1))/2;
            cout << ans << endl;
            continue;
        }
        vector<char> arr;
        for(auto it : st) arr.push_back(it);
        int sz = arr.size();
        unordered_map<char,int> mpp;
        ll maxi = 0;
        f(sz-1, a, b, arr, mpp, maxi, k);
        cout << maxi << endl;
    }
    return 0;
}