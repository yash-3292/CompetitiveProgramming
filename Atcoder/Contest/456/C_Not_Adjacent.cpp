#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    int j = 0;
    ll ans = 0;
    while(j < n){
        if(j != 0 && s[j] == s[j-1]) i = j;
        ans = (ans + (j-i+1)) % mod;
        j++;
    }
    cout << ans << endl;
    return 0;
}