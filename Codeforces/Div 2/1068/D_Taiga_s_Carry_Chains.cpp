#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        for(int i=30; i>=0; i--){
            if(n & (1<<i)) s += "1";
            else s += "0";
        }
        int i1;
        int i2;
        int sz = s.size();
        for(int i=0; i<sz; i++){
            if(s[i] == '1'){
                i1 = i;
                break;
            }
        }
        for(int i=sz-1; i>=0; i--){
            if(s[i] == '1'){
                i2 = i;
                break;
            }
        }
        int zero = 0;
        int one = 0;
        for(int i=i1; i<=i2; i++){
            if(s[i] == '0') zero++;
            else one++;
        }
        int comp = 0;
        vector<int> arr;
        int cnt = 0;
        for(int i=i1; i<=i2; i++){
            if(s[i] == '0'){
                if(!cnt){
                    comp++;
                }
                cnt++;
            } else{
                if(cnt) arr.push_back(cnt);
                cnt = 0;
            }
        }
        // if(k > zero+1){
        //     int ans = k + one - 1;
        //     cout << ans << endl;
        //     continue;
        // }
        if(k <= comp+1){
            int ans = k + one - (comp+1);
            cout << ans << endl;
            continue;
        }
        sort(arr.begin(), arr.end());
        int val = 0;
        int temp = k-1;
        for(auto it : arr){
            if(temp >= it){
                val++;
                temp -= it;
            } else{
                break;
            }
        }
        int ans = k + one - (comp+1) + val;
        // cout << i1 << " " << i2 << endl;
        // cout << k << " " << one << " " << comp << " " << val;
        cout << ans << endl;
    }
    return 0;
}