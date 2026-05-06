#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll cnt = 0;
    ll maxi = INT_MIN;
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        cnt += x;
        maxi = max(maxi, cnt);
        if(cnt < 0) cnt = 0;
    }
    cout << maxi << endl;
    return 0;
}