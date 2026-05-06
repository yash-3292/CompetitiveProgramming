#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> suf(2e6, 0);
    int i=b, j=b;
    while(i >= a){
        suf[i+j] += min(i-a+1, c-j+1);
        i--;
    }
    i = b;
    j = b+1;
    while(j <= c){
        suf[i+j] += min(i-a+1, c-j+1);
        j++;
    }
    for(int i=2e6-10; i>=0; i--) suf[i] += suf[i+1];
    ll ans = 0;
    for(int i=c; i<=d; i++) ans += suf[i+1];
    cout << ans << endl;
    return 0;
}