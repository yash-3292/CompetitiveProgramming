#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> divi(int n){
    vector<int> divisor;
    divisor.push_back(1);
    for(int i=2; i*i<=n; i++){
        if(n % i == 0){
            divisor.push_back(i);
            if(i != n/i) divisor.push_back(n/i);
        }
    }
    return divisor;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> divisor = divi(n);
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        ll maxDiff = 0;
        for(int val : divisor){
            ll mini = 1e18;
            ll maxi = 0;
            int i = 0;
            while(i != n){
                ll sum = 0;
                for(int j=i+0; j<i+val; j++){
                    sum += arr[j];
                }
                mini = min(mini, sum);
                maxi = max(maxi, sum);
                i += val;
            }
            maxDiff = max(maxDiff, maxi-mini);
        }
        cout << maxDiff << endl;
    }
    return 0;
}