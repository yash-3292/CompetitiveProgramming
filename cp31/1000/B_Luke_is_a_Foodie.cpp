#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define low first
#define high second

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> arr(n);
        vector<pair<ll,ll>> rangeArr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            rangeArr[i].low = arr[i] - x;
            rangeArr[i].high = arr[i] + x;
        }
        pair<int,int> range = rangeArr[0];
        int cnt = 0;
        for(int i=1; i<n; i++){
            if(range.low < rangeArr[i].low){
                range.low = rangeArr[i].low;
            }
            if(range.high > rangeArr[i].high){
                range.high = rangeArr[i].high;
            }
            if(range.low > range.high){
                cnt++;
                range = rangeArr[i];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
