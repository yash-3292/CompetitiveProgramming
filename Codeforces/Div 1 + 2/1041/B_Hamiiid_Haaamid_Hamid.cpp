#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        if(x == 1 || x == n){
            cout << 1 << endl;
            continue;
        }
        int w1 = 0;
        int w2 = 0;
        for(int i=0; i<n; i++){
            if(i+1 == x) break;
            if(s[i] == '#') w1 = i+1;
        }
        for(int i=n-1; i>=0; i--){
            if(i+1 == x) break;
            if(s[i] == '#') w2 = n-i;
        }
        int ans;
        if(w1 > w2){
            ans = min(w1, n-x);
        } else if(w1 < w2){
            ans = min(w2, x-1);
        } else{
            ans = w1;
        }
        cout << ans+1 << endl;
    }
    return 0;
}