#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<ll> preSum(n);
    preSum[0] = (ll)arr[0];
    for(int i=1; i<n; i++) preSum[i] = preSum[i-1] + (ll)arr[i];
    vector<int> preXor(n);
    preXor[0] = arr[0];
    for(int i=1; i<n; i++) preXor[i] = preXor[i-1] ^ arr[i];
    unordered_map<int,int> xorltor;
    unordered_map<int,vector<int>> xormap;
    xormap[0].push_back(-1);
    for(int i=0; i<n; i++){
        xormap[preXor[i]].push_back(i);
    }
    for(auto it : xormap){
        int sz = it.second.size();
        int odd = -1;
        int even = -1;
        for(int i=sz-1; i>=0; i--){
            if(it.second[i]%2 == 0){
                xorltor[it.second[i]+1] = odd;
                even = it.second[i];
            } else{
                xorltor[it.second[i]+1] = even;
                odd = it.second[i];
            }
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        int xorr = preXor[r];
        if(l > 0) xorr = xorr ^ preXor[l-1];
        if(xorr != 0){
            cout << -1 << endl;
            continue;
        }
        if((r-l+1)%2 == 0 && (xorltor[l] == -1 || xorltor[l] > r)){
            cout << -1 << endl;
            continue;
        }
        ll summ = preSum[r];
        if(l > 0) summ = summ - preSum[l-1];
        if(summ == 0){
            cout << 0 << endl;
            continue;
        } 
        if((r-l+1)%2 == 1){
            cout << 1 << endl;
            continue;
        }
        if(arr[l] == 0 || arr[r] == 0){
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}