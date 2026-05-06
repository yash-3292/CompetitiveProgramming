#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

const int sz = 1e6 + 5;
int spf[sz];

void pre(){
    for(int i=2; i<sz; i++) spf[i] = i;
    for(int i=2; i<sz; i++){
        if(spf[i] == i){
            for(int j=2*i; j<sz; j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int divisorcnt(int n){
    int cnt = 1;
    while(n > 1){
        int p = spf[n];
        int power = 0;
        while(n%p == 0){
            n /= p;
            power++;
        }
        cnt *= (power+1);
    }
    return cnt;
}

int main(){
    pre();
    int n;
    cin >> n;
    vector<ll> arr(n+1);
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<=n; i++) arr[i] = (arr[i-1]*2)%mod;
    int ans = 0;
    for(int i=0; i<n; i++){
        int x = i;
        int y = n-i;
        ll val = arr[x];
        int cnt = divisorcnt(y);
        val = (val*(ll)cnt)%mod;
        ans = (ans+val)%mod;
    }
    cout << ans << endl;
    return 0;
}