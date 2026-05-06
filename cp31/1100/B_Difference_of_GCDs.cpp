#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        int flag = 1;
        vector<int> ans;
        for(int i=1; i<=n; i++){
            if(l % i == 0){
                ans.push_back(l);
                continue;
            }
            int num = l + i - l%i;
            if(!(l <= num && num <= r)){
                flag = 0;
                break;
            }
            ans.push_back(num);
        }
        if(flag){
            cout << "YES" << endl;
            for(int i=0; i<n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        } else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
}