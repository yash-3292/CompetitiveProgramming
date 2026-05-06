#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int val = __gcd(a,b);
        if(a == b){
            cout << 0 << endl;
        } else if(a == val || b == val){
            cout << 1 << endl;
        } else{
            cout << 2 << endl;
        }
    }
    return 0;
}