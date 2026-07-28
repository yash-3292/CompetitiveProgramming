#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int x, y, k;
    cin >> x >> y >> k;
    int mini = min(x,y);
    cout << 0 << " " << 0 << " " << mini << " " << mini << endl;
    cout << mini << " " << 0 << " " << 0 << " " << mini << endl;
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