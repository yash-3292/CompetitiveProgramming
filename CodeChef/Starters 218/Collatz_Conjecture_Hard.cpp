#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n&1){
            if(n == 1) cout << 0 << endl;
            else if(n == 3) cout << 1 << endl;
            else cout << -1 << endl;
            continue;
        } 
        n /= 2;
        if(n&1){
            if(n == 1) cout << 1 << endl;
            else if(n == 3) cout << 2 << endl;
            else cout << -1 << endl;
            continue;
        }
        n *= 2;
        ll ans = 0;
        ll temp = n;
        while(true){
            temp = n;
            ans--;
            while(temp%4 == 0){
                n = temp;
                ans++;
                temp >>= 1;
            }
            if(n == 4){
                ans += 2;
                break;
            }
            if(n == 12){
                ans += 3;
                break;
            }
            n += 4;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}