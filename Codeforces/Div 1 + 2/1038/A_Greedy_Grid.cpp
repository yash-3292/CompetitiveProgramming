#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    if(n == 1 || m == 1){
        cout << "NO" << endl;
        return;
    }
    if(n > 2 || m > 2){
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