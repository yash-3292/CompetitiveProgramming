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
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i=0; i<k; i++){
            if(s[i] == '0') zero++;
            else if(s[i] == '1') one++;
            else two++;
        } 

        string ans(n, '+');
        if(n == k){
            for(int i=0; i<n; i++) cout << '-';
            cout << endl;
            continue;
        }
        for(int i=0; i<zero; i++){
            ans[i] = '-';
        }
        for(int i=n-1; i>=n-one; i--){
            ans[i] = '-';
        }
        for(int i=zero; i<zero+two; i++){
            ans[i] = '?';
        }
        for(int i=n-one-1; i>=n-one-two; i--){
            ans[i] = '?';
        }
        cout << ans << endl;
    }
    return 0;
}