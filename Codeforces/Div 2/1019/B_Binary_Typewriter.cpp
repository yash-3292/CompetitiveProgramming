#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    int val = 0;
    for(int i=0; i<n; i++){
        if(i == 0){
            if(s[i] == '1') val++;
        }
        else if(s[i] != s[i-1]) val++;
    }
    if(val > 2) val -= 2;
    else if(val > 1) val--;
    ans += val;
    cout << ans << endl; 
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