#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int x;
    cin >> x;
    int cnt = 1;
    while(x != 0){
        x /= 10;
        cnt *= 10;
    }
    cout << cnt+1 << endl;
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