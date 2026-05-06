#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int val = __gcd(x, y);
        if(val > 1){
            cout << 0 << endl;
            continue;
        }
        val = __gcd(x+1, y);
        if(val > 1){
            cout << 1 << endl;
            continue;
        }
        val = __gcd(x, y+1);
        if(val > 1){
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}