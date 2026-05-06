#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        ll n, k, x;
        cin >> n >> k >> x;
        if(x > n*(n+1)/2){
            cout << "NO" << endl;
            continue;
        }
        ll sum1 = k*(k+1)/2;
        ll sum2 = (n-k)*k + sum1;
        if(sum1 <= x && x <= sum2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}