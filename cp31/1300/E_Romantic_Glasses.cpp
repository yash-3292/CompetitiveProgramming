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
        map<ll,int> mpp;
        ll sum = 0;
        int flag = 0;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++){
            if(i&1) sum -= (ll)arr[i];
            else sum += (ll)arr[i];
            if(sum == 0){
                flag = 1;
                break;
            }
            if(mpp[sum] > 0){
                flag = 1;
                break;
            }
            mpp[sum]++;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}