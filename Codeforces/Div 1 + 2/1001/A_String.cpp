#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int one = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1') one++;
    }
    cout << one << endl;
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