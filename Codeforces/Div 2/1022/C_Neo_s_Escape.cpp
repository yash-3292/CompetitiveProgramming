#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(temp.empty()) temp.push_back(arr[i]);
        else{
            if(temp.back() != arr[i]) temp.push_back(arr[i]);
        }
    }
    int m = temp.size();
    if(m == 1){
        cout << 1 << endl;
        return;
    }
    int ans = 0;
    if(temp[0] > temp[1]){
        ans++;
    }
    if(temp[m-1] > temp[m-2]) ans++;
    for(int i=1; i<m-1; i++){
        if(temp[i-1] < temp[i] && temp[i] > temp[i+1]) ans++;
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