#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int x, y;
    cin >> x >> y;
    for(int i=0; i*9<=x; i++){
        int val = x - i*9;
        if(y == val+1){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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