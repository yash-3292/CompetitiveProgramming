#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    unordered_map<int,int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    vector<int> temp(n);
    for(int i=0; i<n; i++){
        if(mpp[arr[i]] == 1){
            temp[i] = 1;
        } else{
            temp[i] = 0;
        }
    }
    int ind = -1;
    int maxi = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(temp[i]){
            cnt++;
            if(cnt > maxi){
                maxi = cnt;
                ind = i+1;
            }
        } else{
            cnt = 0;
        }
    }
    if(ind == -1){
        cout << 0 << endl;
        return;
    }
    cout << ind-maxi+1 << " " << ind << endl;
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