#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,int> freq;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    vector<pair<int,int>> temp;
    for(auto it : freq){
        temp.push_back(it);
    }
    int m = temp.size();
    for(int i=m-1; i>=0; i--){
        bool flag = true;
        if(i < m-1){
            if(temp[i+1].first - temp[i].first  <= k){
                flag = false;
            }
        }
        if(flag){
            if(temp[i].second&1){
                flag = true;
            } else{
                flag = false;
            }
        }
        if(!flag){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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