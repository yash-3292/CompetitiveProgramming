#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll count(int n, int k, int a, int b, vector<int>& arr){
    ll ans = 0;
    int l = 0;
    int r = 0;
    map<int,int> freq;
    while(r < n){
        freq[arr[r]]++;
        while(freq.size() > k && l <= r){
            freq[arr[l]]--;
            if(freq[arr[l]] == 0) freq.erase(arr[l]);
            l++;
        }
        int len = r - l + 1;
        int val = min(len - (a-1), b - a + 1);
        val = max(0, val);
        ans += (ll)val;
        r++;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll ans = count(n, k, l, r, arr);
        ans -= count(n, k-1, l, r, arr);
        cout << ans << endl;
    }
}