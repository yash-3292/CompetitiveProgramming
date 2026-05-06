#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if(a > b){
            if((a&1) && a == b+1){
                cout << y << endl;
            } else{
                cout << -1 << endl;
            }
            continue;
        }
        ll ans = 0;
        while(a != b){
            if(a&1){
                ans += (ll)x;
            } else{
                ans += (ll)min(x, y);
            }
            a++;
        }
        cout << ans << endl;
    }
    return 0;
}