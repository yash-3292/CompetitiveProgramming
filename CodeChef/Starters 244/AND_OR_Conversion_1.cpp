#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    string x, y;
    for(int i=0; i<n; i++){
        if(i == 0 || a[i] != a[i-1]){
            x += a[i];
        }
        if(i == 0 || b[i] != b[i-1]){
            y += b[i];
        }
    }
    if(x.size() > y.size()){
        cout << "Yes" << endl;
        return;
    }
    if(x.size() == y.size() && x[0] == y[0]){
        cout << "Yes" << endl;
        return;
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