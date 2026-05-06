#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a > 2*b || b > 2*a){
            cout << "NO" << endl;
            continue;;
        }
        ll sum = a + b;
        if(sum % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}