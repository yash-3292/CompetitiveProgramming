#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, vector<int>> mpp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mpp[arr[i]].push_back(i+1);
    } 
    vector<ll> preSum(n);
    vector<ll> sufSum(n);
    preSum[0] = 0;
    for(int i=1; i<n; i++){
        preSum[i] = preSum[i-1] + (ll)arr[i-1];
    }
    sufSum[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        sufSum[i] = sufSum[i+1] + (ll)arr[i+1];
    }
    vector<ll> sum(n);
    for(int i=0; i<n; i++){
        sum[i] = preSum[i] + sufSum[i];
    }
    map<int,int> check;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(sum[i] >= (ll)arr[i]){
            ll temp = sum[i] - arr[i];
            if(temp > 1e7) continue;
            int val = (int)temp;
            if(!check[val]){
                check[val] = i+1;
                for(int num : mpp[val]){
                    if(num == i+1) continue;
                    ans.push_back(num);
                }
            } else{
                if(check[val] == 1e7) continue;
                if(arr[check[val]-1] == val){
                    ans.push_back(check[val]);
                    check[val] = 1e7;
                }
            }
        }
    }
    int size = ans.size();
    cout << size << endl;
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}