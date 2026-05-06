#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n&1){
            if(n == 1 || n == 3) cout << "Yes" << endl;
            else cout << "No" << endl;
            continue;
        } 
        n /= 2;
        if(n&1){
            if(n == 1 || n == 3) cout << "Yes" << endl;
            else cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}