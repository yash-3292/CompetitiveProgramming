#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    string a, b;
    cin >> a >> b;
    int n = a.size();
    for(int i=0; i<n; i++){
        if(a[i] < 'a'){
            a[i] += ('a'-'A');
        }
    }
    for(int i=0; i<n; i++){
        if(b[i] < 'a'){
            b[i] += ('a'-'A');
        }
    }
    if(a < b){
        cout << -1 << endl;
    } else if(a > b){
        cout << 1 << endl;
    } else{
        cout << 0 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}