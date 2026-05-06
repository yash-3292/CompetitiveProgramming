#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        if(n == x){
            cout << n << endl;
            continue;
        }
        ll temp = n;
        ll num;
        while((temp&n) != x && temp > 0){
            ll val = (temp)&(temp-1);
            num = (val^temp);
            temp = val;
        }
        if((temp&n) != x){
            cout << -1 << endl;
            continue;
        }
        temp += (num<<1);
        if((temp&n) != x){
            cout << -1 << endl;
            continue;
        }
        cout << temp << endl;
    }
    return 0;
}