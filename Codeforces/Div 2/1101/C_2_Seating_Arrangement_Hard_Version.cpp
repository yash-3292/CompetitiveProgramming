#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;
    ll amb = 0;
    ll table = x;
    ll seat = 0;
    ll ans = 0;
    for(auto ch : u){
        if(ch == 'A'){
            if(seat == 0){
                if(table > 0){
                    table--;
                    seat += s-1;
                    ans++;
                }
            } else{
                seat--;
                amb++;
                ans++;
            }
        } else if(ch == 'I'){
            if(table > 0){
                table--;
                seat += s-1;
                ans++;
            }
        } else{
            if(seat > 0){
                seat--;
                ans++;
            } else{
                if(table > 0 && amb > 0){
                    seat += s-1;
                    table--;
                    amb--;
                    ans++;
                }
            }
        }
    }
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