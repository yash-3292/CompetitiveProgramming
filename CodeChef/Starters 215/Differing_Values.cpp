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
        cin >> s;
        int one = 0;
        int zero = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') one++;
            else zero++;
        }
        int val = n%(2*k);
        int ans;
        if(val <= k) ans = val;
        else ans = 2*k-val;
        if(abs(zero-one) <= ans){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}