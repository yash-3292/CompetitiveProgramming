#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int x,y,z;
        cin >> x >> y >> z;
        int cnt = 0;
        if(x) cnt++;
        if(y) cnt++;
        if(z) cnt++;
        if(cnt >= 2) ans++;
    }
    cout << ans << endl;
    return 0;
}