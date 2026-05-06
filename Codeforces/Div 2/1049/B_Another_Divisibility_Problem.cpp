#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    vector<ll> power = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    while(t--){
        ll x;
        cin >> x;
        string s = to_string(x);
        int n = s.size();
        ll y = power[n+1] - x -1;
        cout << y << endl;
    }
    return 0;
}