#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    
    ll ans = 0;
    for(int b=0; b<31; b++){
        ll res = 0;
        int sum = 0;
        ll evenCnt = 1;
        ll oddCnt = 0;
        ll evenSum = -1;
        ll oddSum = 0;
        for(int i=0; i<n; i++){
            if(arr[i]&(1<<b)) sum++;
            if(sum&1){
                ll val = (evenCnt*i - evenSum)%mod;
                res = (res + val)%mod;
                oddCnt++;
                oddSum += i;
            } else{
                ll val = (oddCnt*i - oddSum)%mod;
                res = (res + val)%mod;
                evenCnt++;
                evenSum += i;
            }
        }
        ans = (ans + (res*(1<<b))%mod)%mod;
    }
    cout << ans << endl;
    return 0;
}