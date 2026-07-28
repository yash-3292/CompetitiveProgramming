#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int o = 0;
    int maxlen = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1') o++;
    }
    if(o <= k){
        cout << "Alice" << endl;
        return;
    }
    if(n <= 2*k-1){
        cout << "Alice" << endl;
    } else{
        cout << "Bob" << endl;
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