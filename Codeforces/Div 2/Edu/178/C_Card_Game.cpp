#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 2){
        if(s[0] == 'A') cout << "Alice" << endl;
        else cout << "Bob" << endl;
        return;
    }
    if(s[n-2] == 'A' && s[n-1] == 'A'){
        cout << "Alice" << endl;
        return;
    }
    if(s[n-1] == 'A' && s[0] == 'A'){
        cout << "Alice" << endl;
        return;
    }
    for(int i=0; i<n-1; i++){
        if(s[i] == 'B'){
            cout << "Bob" << endl;
            return;
        }
    }
    cout << "Alice" << endl;
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