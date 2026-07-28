#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, l, r;
    cin >> n >> l >> r; 
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int sum1 = 0;
    int sum2 = 0;
    l--; r--;
    for(int i=0; i<n; i++){
        if(i < l){
            sum1 += arr[i];
        } else if(i > r){
            sum2 += arr[i];
        }
    }
    cout << max(sum1, sum2) << endl;
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