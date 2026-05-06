#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i=1; i<=n*n; i++){
            int val = i;
            if(i%n != 1) val += i-1;
            if(i%n != 0) val += i+1;
            if((i-1)/n != 0) val += i-n;
            if(i/n < n-1) val += i+n;
            ans = max(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}