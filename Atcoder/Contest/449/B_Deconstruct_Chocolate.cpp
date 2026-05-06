#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int h, w, q;
    cin >> h >> w >> q;
    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            int ans = x * w;
            cout << ans << endl;
            h -= x;
        } else{
            int ans = x * h;
            cout << ans << endl;
            w -= x;
        }
    }
    return 0;
}