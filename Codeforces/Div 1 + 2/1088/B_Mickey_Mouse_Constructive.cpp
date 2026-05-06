#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 676767677;

int f(int n){
    int ans = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            if(i == n/i) ans++;
            else ans += 2;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int ans = f(abs(x-y));
        if(x == y) ans++;
        cout << ans << endl;
        for(int i=0; i<x; i++) cout << 1 << " ";
        for(int i=0; i<y; i++) cout << -1 << " ";
        cout << endl;
    }
    return 0;
}