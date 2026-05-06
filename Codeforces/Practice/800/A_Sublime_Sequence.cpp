#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, n;
        cin >> x >> n;
        if(n&1){
            cout << x << endl;
        } else{
            cout << 0 << endl;
        }
    }
    return 0;
}