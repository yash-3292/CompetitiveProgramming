#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int two = 0;
    for(int i=0; i<n; i++){
        if(arr[i] >= 3){
            cout << "YES" << endl;
            return;
        }
        if(arr[i] == 2) two++;
    }
    if(two >= 2) cout << "YES"  << endl;
    else cout << "NO" << endl;
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