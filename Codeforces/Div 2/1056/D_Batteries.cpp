#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    for(int l=1; ; l++){
        for(int i=0; i<n; i++){
            cout << i+1 << " " << (i+l)%n+1 << "\n";
            cout << flush;
            int work;
            cin >> work;
            if(work) return;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}