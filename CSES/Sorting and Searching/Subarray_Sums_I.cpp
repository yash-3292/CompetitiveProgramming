#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<int>& arr, int x){
    int n = arr.size();
    ll sum = 0;
    int i = 0;
    int j = 0;
    ll cnt = 0;
    while(j < n){
        sum += (ll)arr[j];
        while(sum > (ll)x && i <= j){
            sum -= (ll)arr[i];
            i++;
        }
        cnt += (ll)j-(ll)i+1;
        j++;
    }
    return cnt;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll val1 = solve(arr, x-1);
    ll val2 = solve(arr, x);
    ll ans = val2 - val1;
    cout << ans << endl;
    return 0;
}