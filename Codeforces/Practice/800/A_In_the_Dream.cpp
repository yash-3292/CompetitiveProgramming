#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c -= a;
        d -= b;
        int flag = 1;
        if(a>=b){
            if(a-2*b >= 3) flag = 0;
        } else{
            if(b-2*a >= 3) flag = 0;
        }
        if(c>=d){
            if(c-2*d >= 3) flag = 0;
        } else{
            if(d-2*c >= 3) flag = 0;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}