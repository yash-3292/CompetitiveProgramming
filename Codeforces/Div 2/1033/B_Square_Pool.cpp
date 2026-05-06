#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll s;
        cin >> n >> s;
        int ans = 0;
        while(n--){
            int dx, dy;
            ll x, y;
            cin >> dx >> dy >> x >> y;
            if(dx == -1 && dy == -1){
                if(x == y){
                    ans++;
                }
            } else if(dx == -1 && dy == 1){
                if(x+y == s){
                    ans++;
                }
            } else if(dx == 1 && dy == -1){
                if(x+y == s){
                ans++;
                }
            } else{
                if(x == y){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}