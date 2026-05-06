#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    map<int,int> mpp;
    for(int k=2; k<=1e3; k++){
        ll sum = 1 + (ll)k + (ll)(k*k);
        ll val = (ll)(k*k*k);
        while(sum <= (ll)(1e6+4)){
            mpp[(int)sum] = 1;
            sum += val;
            val *= (ll)k;
        }

    }
    while(t--){
        int n;
        cin >> n;
        if(mpp[n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}