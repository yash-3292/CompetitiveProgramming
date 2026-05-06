#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<ll> arr(n);
        vector<ll> sum(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i == 0) sum[i] = arr[i];
            else{
                sum[i] = arr[i] + sum[i-1];
            }
        }
        ll maxi = 0;
        for(int i=0; i<n-1; i++){
            maxi = max(maxi, __gcd(sum[i], sum[n-1]));
        }
        cout << maxi << endl;
    }
    return 0;
}