#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = 1;
        int flag = 0;
        while(j != n){
            if(arr[j] - arr[i] == k){
                flag = 1;
                break;
            } else if(arr[j] - arr[i] > k){
                i++;
                if(i == j) j++;
            } else{
                j++;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}