#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, int x, vector<int>& arr){
    int n = arr.size();
    ll ans;
    if(i > 0 && i < n-1 && arr[i-1] == x && arr[i+1] == x){
        ans = (ll)(n-1) + (ll)i * (ll)(n-i-1)*2;
    } else if(i > 0 && arr[i-1] == x){
        ans = (ll)i * (ll)(n-i);
    } else if(i < n-1 && x == arr[i+1]){
        ans = (ll)(i+1) * (ll)(n-i-1);
    } else{
        ans = 0;
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) arr[i] = i+1;
    ll ans = ((ll)n * (ll)(n+1) * (ll)(n+2))/6;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        ans += f(i, arr[i], arr);
        ans -= f(i, x, arr);
        arr[i] = x;
    }
    for(int j=0; j<m; j++){
        int i, x;
        cin >> i >> x;
        i--;
        ans += f(i, arr[i], arr);
        ans -= f(i, x, arr);
        arr[i] = x;
        cout << ans << endl;
    }
    return 0;
}