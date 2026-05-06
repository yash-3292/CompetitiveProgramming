#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    ll x = 1;
    ll y = 3;
    vector<ll> arr1;
    vector<ll> arr2;
    while(x <= 1e10){
        arr1.push_back(x);
        arr2.push_back(y);
        x = x*(ll)2 + (ll)1;
        y += (ll)2;
    }
    while(t--){
        ll x;
        cin >> x;
        int index = upper_bound(arr1.begin(), arr1.end(), x) - arr1.begin();
        if(index != 0){
            if(arr1[index-1] == x) index--;
        }
        ll num = arr2[index];
        cout << num << endl;
    }
    return 0;
}