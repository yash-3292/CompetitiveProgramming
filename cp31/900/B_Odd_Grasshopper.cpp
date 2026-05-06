#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, n;
        cin >> x >> n;
        if(x&1){
            if(n%4 == 0){
                cout << x << endl;
            } else if(n%4 == 1){
                cout << x + n << endl;
            } else if(n%4 == 2){
                cout << x - 1 << endl;
            } else{
                cout << x - n - 1 << endl;
            }
        } else{
            if(n%4 == 0){
                cout << x << endl;
            } else if(n%4 == 1){
                cout << x - n << endl;
            } else if(n%4 == 2){
                cout << x + 1 << endl;
            } else{
                cout << x + n + 1 << endl;
            }
        }
    }
    return 0;
}