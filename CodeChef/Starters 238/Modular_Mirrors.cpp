#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    if(n%3 != 2){
        cout << -1 << endl;
        return;
    }
    for(int i=0; i<n; i++){
        int x = i%6;
        if(x == 0 || x == 1) cout << 1 << " ";
        if(x == 2 || x == 5) cout << 0 << " "; 
        if(x == 3 || x == 4) cout << m-1 << " "; 
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}