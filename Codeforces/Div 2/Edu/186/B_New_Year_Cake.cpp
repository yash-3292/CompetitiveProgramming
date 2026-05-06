#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int a, int b){
    int cnt = 0;
    int val = 1;
    while(true){
        if(cnt&1){
            if(a < val) return cnt;
            a -= val;
        } else{
            if(b < val) return cnt;
            b -= val;
        }
        val *= 2;
        cnt++;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = max(f(a,b), f(b,a));
        cout << ans << endl;
    }
    return 0;
}