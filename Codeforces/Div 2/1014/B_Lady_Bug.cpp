#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int one1 = 0;
    int zero1 = 0;
    int one2 = 0;
    int zero2 = 0;
    for(int i=0; i<n; i+=2){
        if(a[i] == '1') one1++;
        if(b[i] == '0') zero2++;
    }
    for(int i=1; i<n; i+=2){
        if(a[i] == '1') one2++;
        if(b[i] == '0') zero1++;
    }
    if(one1 <= zero1 && one2 <= zero2){
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