#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int k = k1+k2;
    vector<int> arr(3000000, 0);
    int maxi = 0;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++){
        int x = abs(a[i]-b[i]);
        arr[1]++;
        arr[x+1]--;
        maxi = max(maxi, x);
    }
    for(int i=2; i<=maxi+1; i++){
        arr[i] = arr[i] + arr[i-1];
    }
    ll ans = 0;
    int temp = 0;
    for(int i=maxi; i>=1; i--){
        if(k >= arr[i]){
            k -= arr[i];
            arr[i] = 0;
        } else{
            arr[i] -= k;
            k = 0;
        }
        if(arr[i] > temp){
            ans += ((ll)i*(ll)i)*(ll)(arr[i]-temp);
            temp = arr[i];
        }
    }
    if(k&1){
        ans++;
    }
    cout << ans << endl;
    return 0;
}