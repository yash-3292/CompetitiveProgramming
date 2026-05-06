#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 1;
        int i = 2;
        while(i*i <= n){
            if(n%i == 0){
                ans *= i;
                while(n%i == 0) n /= i;
            } 
            i++;
        }
        if(n > 1){
            ans *= n;
            n = 1;
        }
        cout << ans << endl;
    }
    return 0;
}