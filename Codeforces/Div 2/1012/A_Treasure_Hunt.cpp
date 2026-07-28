#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int x, y, a;
    cin >> x >> y >> a;
    a++;
    a = a % (x+y);
    if(a == 0){
        cout << "YES" << endl;
        return;
    }
    if(a <= x){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
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