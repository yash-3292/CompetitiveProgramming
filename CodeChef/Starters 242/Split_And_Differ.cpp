#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=1; i<n; i++){
        if(arr[i] == 1 && arr[i-1] == 1){
            cout << -1 << endl;
            return;
        }
        if(arr[i] == 2 && arr[i-1] == 2){
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(ans.empty()){
            ans.push_back(arr[i]);
        } else{
            if(arr[i] == ans.back()){
                if(i+1 < n && arr[i+1] == 1){
                    ans.push_back(1);
                    ans.push_back(arr[i]-1);
                } else{
                    ans.push_back(arr[i]-1);
                    ans.push_back(1);
                }
            } else{
                ans.push_back(arr[i]);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
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