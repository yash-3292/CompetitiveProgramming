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
        for(int i=0; i<2*n; i++){
            int x;
            cin >> x;
            mpp[x]++;
        }
        int even = 0;
        int oddNum = 0;
        int ans = 0;
        for(auto it : mpp){
            if(it.second&1){
                oddNum += it.second;
                ans++;
            } else{
                int val = it.second/2;
                if(val&1){
                    ans += 2;
                } else{
                    even++;
                }
            }
        }
        int cont = (even/2)*2;
        if((oddNum >= 2) && (even&1)) cont++; 
        ans += cont*2;
        cout << ans << endl;
    }
    return 0;
}