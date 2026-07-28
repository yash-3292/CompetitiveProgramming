#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int total = a + b + c;
    if(total%3 != 0){
        cout << "NO" << endl;
        return;
    }
    if(a <= total/3 && b <= total/3){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
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