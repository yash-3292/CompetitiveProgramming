#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> diff(31, n);
        ll sum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            for(int j=0; j<=30; j++){
                if(arr[i] & (1<<j)){
                    diff[j]--;
                }
            }
        }
        for(int i=30; i>=0; i--){
            if(k >= diff[i]){
                sum += (ll)(1<<i);
                k -= diff[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}