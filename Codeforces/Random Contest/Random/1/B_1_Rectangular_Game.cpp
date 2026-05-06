#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            arr.push_back(i);
            if(i != n/i) arr.push_back(n/i);
        }
    }
    arr.push_back(n);
    sort(arr.begin(), arr.end());
    ll ans = n;
    for(auto it : arr){
        while(n%it == 0){
            n /= it;
            ans += (ll)n;
        }
    }
    cout << ans << endl;
    return 0;
}