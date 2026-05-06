#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        vector<int> premin(n);
        premin[0] = arr[0];
        for(int i=1; i<n; i++){
            premin[i] = min(premin[i-1], arr[i]);
        }
        vector<ll> preminSum(n);
        preminSum[0] = (ll)premin[0];
        for(int i=1; i<n; i++){
            preminSum[i] = preminSum[i-1] + (ll)premin[i];
        }
        vector<bool> sorted(n);
        sorted[0] = true;
        for(int i=1; i<n; i++){
            if(sorted[i-1] && arr[i-1] >= arr[i]){
                sorted[i] = true;
            } else{
                sorted[i] = false;
            }
        }
        vector<int> mindiff(n, -1);
        mindiff[0] = INT_MAX;
        for(int i=1; i<n; i++){
            if(sorted[i]){
                mindiff[i] = min(mindiff[i-1], arr[i-1]-arr[i]);
            } else break;
        }
        ll mini = preminSum[n-1];
        for(int i=0; i<n-1; i++){
            ll val = preminSum[i];
            if(sorted[i]){
                val += (ll)min(mindiff[i], arr[i+1]);
            }
            mini = min(mini, val);
        }
        cout << mini << endl;
    }
    return 0;
}