#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cardBoard(ll mid, vector<int>& arr){
    int n = arr.size();
    ll val = 0;
    for(int i=0; i<n; i++){
        val += (2*mid+(ll)arr[i])*(2*mid+(ll)arr[i]);
    }
    return val;
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll i = 1;
        ll j = INT_MAX;
        ll w = -1;
        while(i <= j){
            ll mid = i + (j-i)/2;
            if(4*(double)n*(double)mid > c/(double)mid){
                j = mid-1;
                continue;
            }
            ll ans = cardBoard(mid, arr);
            if(ans > c){
                j = mid-1;
            } else if(ans < c){
                i = mid+1;
            } else{
                w = mid;
                break;
            }
        }
        cout << w << endl;
    }
    return 0;
}