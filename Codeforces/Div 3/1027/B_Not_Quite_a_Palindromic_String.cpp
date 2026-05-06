#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n ,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int one = 0;
        int zero = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') one++;
            else zero++;
        }
        int x;
        if(zero&1) x = n/2 - 1;
        else x = n/2;
        int mini = min(zero, one);
        if(x%2 == k%2){
            if(zero&1){
                if(k >= x - mini + 1){
                    cout << "YES" << endl;
                    continue;
                }
            } else{
                if(k >= x - mini){
                    cout << "YES" << endl;
                    continue;
                }

            }
        }
        cout << "NO" << endl;
    }
    return 0;
}