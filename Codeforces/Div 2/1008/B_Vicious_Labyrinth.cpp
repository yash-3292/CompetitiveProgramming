#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    if(k%2 == 0){
        for(int i=1; i<=n; i++){
            if(i == n-1){
                cout << n << " ";
            } else{
                cout << n-1 << " ";
            }
        }
    } else{
        for(int i=1; i<=n; i++){
            if(i == n){
                cout << n-1 << " ";
            } else{
                cout << n << " ";
            }
        }
    }
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