#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    arr[0] = (int)x;
    for(int i=1; i<n; i++){
        ll val = (ll)arr[i-1]*a;
        val += b;
        val = val%c;
        arr[i] = (int)val;
    }
    deque<int> dq;
    int i = 0;
    int j = 0;
    ll ans = 0;
    while(j < n){
        while(!dq.empty() && arr[dq.back()] > arr[j]) dq.pop_back();
        dq.push_back(j);
        if(j-i+1 > k){
            if(dq.front() == i) dq.pop_front();
            i++;
        }
        if(j-i+1 == k) ans ^= arr[dq.front()];
        j++;
    }
    cout << ans << endl;
    return 0;
}