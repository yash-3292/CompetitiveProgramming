#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int x, y;
    cin >> x >> y;
    if(x > y){
        cout << "NO" << endl;
        return;
    }
    if(x==0 && (y%2 == 0)){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int cnt = 2;
    if((x+y)%2 == 0){
        x--;
    } else{
        y--;
    }
    while(x > 0){
        cout << 1 << " " << cnt << endl;
        cout << cnt << " " << cnt+1 << endl;
        cnt += 2;
        x--;
        y--;
    }
    while(y > 0){
        cout << 1 << " " << cnt << endl;
        cnt++;
        y--;
    }
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