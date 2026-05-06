#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int ans;
        if(x >= 2*y){
            ans = 0;
            ans += y*2;
            ans += (x-2*y)/3;
        } else{
            ans = ((x+y)/3)*2;
        }
        cout << ans << endl;
    }
    return 0;
}