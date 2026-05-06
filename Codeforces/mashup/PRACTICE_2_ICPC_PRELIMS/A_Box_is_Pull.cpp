#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans;
        int dx = abs(x1-x2);
        int dy = abs(y1-y2);
        if(x1 == x2){
            ans = dy;
        } else if(y1 == y2){
            ans = dx;
        } else{
            ans = dx+dy+2;
        }
        cout << ans << endl;
    }
    return 0;
}