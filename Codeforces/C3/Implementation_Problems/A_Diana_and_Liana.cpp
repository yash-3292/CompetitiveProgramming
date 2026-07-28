#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    vector<int> a(m), b(s);
    for(int i=0; i<m; i++) cin >> a[i];
    for(int i=0; i<s; i++) cin >> b[i];
    int thres = m - n*k;
    unordered_map<int,int> freq;
    unordered_map<int,int> mpp;
    for(int i=0; i<s; i++){
        freq[b[i]]++;
    }
    int cnt = 0;
    int j = 0;
    vector<int> arr(m);
    for(int i=0; i<m; i++){
        while(j < m && (j-i < k || cnt < freq.size())){
            if(freq.find(a[j]) != freq.end()){
                mpp[a[j]]++;
                if(mpp[a[j]] == freq[a[j]]){
                    cnt++;
                }
            }
            j++;
        }
        if(cnt == freq.size() && j-i >= k) arr[i] = j;
        else arr[i] = -1;
        if(freq.find(a[i]) != freq.end()){
            if(mpp[a[i]] == freq[a[i]]) cnt--;
            mpp[a[i]]--;
        }
    }
    vector<int> ans;
    int l = -1;
    int r = -1;
    for(int i=0; i<m; i++){
        if(arr[i] == -1) continue;
        int cost = (i%k) + arr[i] - i - k;
        if(cost <= thres){
            l = i;
            r = arr[i]-1;
            break;
        }
    }
    if(l == -1){
        cout << -1 << endl;
        return;
    }
    for(int j=0; j<(l%k); j++){
        ans.push_back(j);
    }
    int remove = r - l + 1 - k;
    for(int j=l; j<=r; j++){
        if(freq.find(a[j]) != freq.end()){
            freq[a[j]]--;
            if(freq[a[j]] == 0) freq.erase(a[j]);
        } else{
            if(remove){
                ans.push_back(j);
                remove--;
            }
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans) cout << it+1 << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}