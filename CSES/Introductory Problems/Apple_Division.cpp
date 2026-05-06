#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int i, vector<ll>& arr, ll val, ll& mini){
    if(i < 0){
        mini = min(mini, abs(val));
        return;
    }
    f(i-1, arr, val-arr[i], mini);
    f(i-1, arr, val+arr[i], mini);
}

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll mini = LLONG_MAX;
    f(n-1, arr, 0, mini);
    cout << mini << endl;
    return 0;
}