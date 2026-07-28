#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if(a > b){
        if(((n&1) == (a&1)) && ((n&1) == (b&1))){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    } else{
        if(((n&1) == (b&1))){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
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