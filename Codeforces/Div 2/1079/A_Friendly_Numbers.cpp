#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int ans = 0;
        for(int i=0; i<100; i++){
            int y = x + i;
            int dy = 0;
            while(y > 0){
                dy += y%10;
                y /= 10;
            }
            if(dy == i) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}