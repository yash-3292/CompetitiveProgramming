#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;
        if(x >= y){
            x -= k;
            if(x < 0) x = 0;
        } else{
            y -= k;
            if(y < 0) y = 0;
        }
        int maxi = max(x, y);
        if(maxi <= k){
            cout << "Alice" << endl;
        } else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}