#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    if(x1 > y1 && x2 < y2){
        cout << "NO" << endl;
        return;
    }
    if(x1 < y1 && x2 > y2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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