#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<int> s(n);
    vector<int> w(n);
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++) cin >> w[i];
    vector<int> maxi(m+1, -1);
    vector<int> cnt(m+1, 1);
    vector<pair<int,int>> arr;
    ll ans = 0;
    for(int i=0; i<n; i++){
        if(maxi[s[i]] == -1) maxi[s[i]] = w[i];
        else{
            if(w[i] > maxi[s[i]]){
                arr.push_back({maxi[s[i]], s[i]});
                maxi[s[i]] = w[i];
            } else{
                arr.push_back({w[i], s[i]});
            }
        }
    } 
    for(int i=1; i<=m; i++){
        ans += (ll)(maxi[i]);
    }
    k -= m;
    int sz = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=sz-1; i>=0; i--){
        // cout << arr[i].first << " " << arr[i].second << endl;
        if(cnt[arr[i].second] < x && k > 0){
            ans += (ll)arr[i].first;
            k--;
            cnt[arr[i].second]++;
        }
    }
    cout << ans << endl;
    return 0;
}