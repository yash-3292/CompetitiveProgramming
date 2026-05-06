#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll p, q;
        cin >> p >> q;
        if(q <= p){
            cout << "Alice" << endl;
            continue;
        }
        ll dif = q - p;
        if(dif*2 <= p){
            cout << "Bob" << endl;
        } else{
            cout << "Alice" << endl;
        }
    }
    return 0;
}