#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        map<int,int> mpp;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            mpp[x]++;
        }
        int ans = 0;
        for(auto it : mpp){
            int val = it.first;
            int freq = it.second;
            if(freq < val){
                ans += freq;
            } else if(freq > val){
                ans += (freq-val);
            }
        }
        cout << ans << endl;
    }
    return 0;
}