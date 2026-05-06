#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    map<pair<int,int>,int> mppPos;
    map<pair<int,int>,int> mppNeg;

    int cnt = 0;
    int zero = 0;
    for(int i=0; i<n; i++){
        if(a[i] != 0 && b[i] == 0) zero++;
        if(a[i] == 0 && b[i] == 0) cnt++;
        if(a[i] != 0 && b[i] != 0){
            int gcd = __gcd(a[i], b[i]);
            int x = a[i] / gcd;
            int y = b[i] / gcd;
            int flag1 = (x > 0);
            int flag2 = (y > 0);
            x = abs(x);
            y = abs(y);
            if(flag1 ^ flag2){
                mppNeg[{x,y}]++;
            } else{
                mppPos[{x,y}]++;
            }
        }
    }
    int maxi = zero;
    for(auto it : mppPos) maxi = max(maxi, it.second);
    for(auto it : mppNeg) maxi = max(maxi, it.second);
    int ans = maxi + cnt;
    cout << ans << endl;
    return 0;
}