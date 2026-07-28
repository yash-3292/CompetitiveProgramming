#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    if(sum%n != 0){
        cout << "NO" << endl;
        return;
    }
    if(sum/n == x){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
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