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
        vector<int> freq(n+1);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            freq[arr[i]]++;
        } 
        sort(arr.begin(), arr.end());
        int mex = 0;
        for(int i=0; i<n; i++){
            if(mex == arr[i]) mex++;
        }
        ll cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > mex || freq[arr[i]] > 1){
                arr[i] = mex;
                cnt++;
            }
        }
        ll sum = 0;
        for(auto val : arr) sum += (ll)val;
        if(k == 1){
            cout << sum << endl;
            continue;
        }
        int flag = 1;
        mex = 0;
        for(int i=0; i<n; i++){
            if(mex == arr[i]) mex++;
        }
        for(int i=0; i<n; i++){
            if(mex < arr[i]) flag = 0;
        }

        if(flag){
            if((k&1) || (cnt==1)){
                cout << sum << endl;
            } else{
                ll ans = sum+cnt;
                cout << ans << endl;
            }
        } else{
            sum = 0;
            cnt = 0;
            for(int val : arr){
                if(val < mex){
                    sum += (ll)val;
                } else{ 
                    sum += (ll)mex;
                    cnt++;
                }
            }
            if(k&1){
                ll ans = sum+cnt;
                cout << ans << endl;
            } else{
                cout << sum << endl;
            }
        }
    }
    return 0;
}