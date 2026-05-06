#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    ll cnt = 0;
    ll ans = 1;
    for(auto ch : s){
        if(ch == 'a') cnt++;
        if(ch == 'b'){
            if(cnt != 0){
                ans = (ans*(cnt+1))%mod;
                cnt = 0;
            }
        }
    }
    if(cnt != 0){
        ans = (ans*(cnt+1))%mod;
        cnt = 0;
    }
    ans--;
    cout << ans << endl;
    return 0;
}