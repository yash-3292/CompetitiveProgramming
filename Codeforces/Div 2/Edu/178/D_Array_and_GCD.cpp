#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxN = 6e6;
bool prime[maxN];
vector<ll> primes;

void pre() {
    for(int i = 0; i < maxN; i++) {
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    for(int i = 2; i * i < maxN; i++) {
        if(prime[i]) {
            for(int j = i * i; j < maxN; j += i) {
                prime[j] = false;
            }
        }
    }
    for(int i=2; i<maxN; i++){
        if(prime[i]) primes.push_back(i);
    }
    int n = primes.size();
    for(int i=1; i<n; i++){
        primes[i] += primes[i-1];
    }
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<ll>());
    for(ll i=1; i<n; i++) arr[i] += arr[i-1];
    ll maxi = 0;
    for(ll i=0; i<n; i++){
        if(arr[i] >= primes[i]){
            maxi = max(maxi, i+1);
        }
    }
    ll ans = n - maxi;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}