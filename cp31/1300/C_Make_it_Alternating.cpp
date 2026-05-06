#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int m = 998244353;

ll fact(ll n){
    if(n == 0) return 1;
    return (fact(n-1) * n) % m;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        ll comb = 1;
        int per = 0;
        ll cnt = 1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) cnt++;
            else{
                per++;
                comb = (comb * cnt) % m;
                cnt = 1;
            }
        }
        per++;
        comb = (comb * cnt) % m;
        int ans = n - per;
        comb = (comb * fact(ans)) % m;
        cout << ans << " " << comb << endl;
    }
    return 0;
}