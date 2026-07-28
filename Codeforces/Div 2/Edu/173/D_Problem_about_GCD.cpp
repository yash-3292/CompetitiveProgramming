#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll l, r, g;
    cin >> l >> r >> g;
    ll mini = l/g;
    if(l%g != 0) mini++;
    ll maxi = r/g;
    if(mini == 1 && maxi == 1){
        cout << g << " " << g << endl;
        return;
    } 
    if(mini >= maxi){
        cout << -1 << " " << -1 << endl;
        return;
    }
    vector<ll> arr1;
    vector<ll> arr2;
    for(ll i=0; i<10; i++){
        if(mini+i <= maxi){
            arr1.push_back(mini+i);
        }
        if(maxi-i >= mini){
            arr2.push_back(maxi-i);
        }
    }
    ll val1 = -1;
    ll val2 = -1;
    ll dist = -1;
    for(auto it1 : arr1){
        for(auto it2 : arr2){
            if(__gcd(it1,it2) == 1){
                if(abs(it2-it1) > dist){
                    dist = abs(it1-it2);
                    val1 = min(it1, it2);
                    val2 = max(it1, it2);
                } else if(abs(it2-it1) == dist && min(it1, it2) < val1){
                    dist = abs(it1-it2);
                    val1 = min(it1, it2);
                    val2 = max(it1, it2);
                }
            } 
        }
    }
    cout << val1*g << " " << val2*g << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}