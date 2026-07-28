#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int mid, vector<int>& a, vector<int>& b){
    int n = a.size();
    int cnt1 = 0;
    int cnt0 = 0;
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(a[i] >= mid && b[i] >= mid){
            temp.push_back(1);
        } else if(a[i] < mid && b[i] < mid){
            if(temp.empty()) temp.push_back(0);
            else{
                if(temp.back() == 1) temp.push_back(0);
            }
        }
    }
    for(auto it : temp){
        if(it == 0) cnt0++;
        else cnt1++;
    }
    return cnt1 > cnt0;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    if(n == 1){
        cout << min(a[0], b[0]) << endl;
        return;
    }
    int l = 1;
    int r = 1e9;
    int ans = 1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(check(mid, a, b)){
            ans = mid;
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
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