#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=1; i<=n; i++) arr.push_back(i);
    if(n&1){
        for(int i=1; i<n; i+=2){
            swap(arr[i], arr[i+1]);
        }
    } else{
        for(int i=0; i<n; i+=2){
            swap(arr[i], arr[i+1]);
        }
    }
    for(auto it : arr) cout << it << " ";
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