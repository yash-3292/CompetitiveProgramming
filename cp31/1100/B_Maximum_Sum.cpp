#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        ll sum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum += arr[i];
        } 
        sort(arr.begin(), arr.end());
        vector<ll> firstSum(k+1, 0);
        vector<ll> lastSum(k+1, 0);
        for(int i=1; i<=k; i++){
            firstSum[i] = arr[2*i-2] + arr[2*i-1] + firstSum[i-1];
        }
        for(int i=1; i<=k; i++){
            lastSum[i] = lastSum[i-1] + arr[n-i];
        }
        ll minSum = 1e18;
        for(int i=0; i<=k; i++){
            minSum = min(minSum, firstSum[i]+lastSum[k-i]);
        }
        ll maxSum = sum - minSum;
        cout << maxSum << endl;
    }
    return 0;
}
