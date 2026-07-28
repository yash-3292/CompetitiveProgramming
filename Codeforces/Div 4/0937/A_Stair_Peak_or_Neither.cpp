#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a < b && b < c){
        cout << "STAIR" << endl;
        return;
    }
    if(a < b && b > c){
        cout << "PEAK" << endl;
        return;
    }
    cout << "NONE" << endl;
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