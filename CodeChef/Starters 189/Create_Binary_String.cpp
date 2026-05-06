#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int maxi = 0;
        int e = max(c, d);
        for(int i=0; i<=n; i++){
            int zero = i;
            int one = n - i;
            int val = 0;
            val += a*zero;
            val += b*one;
            val += e*zero*one;
            maxi = max(maxi, val);
        }
        cout << maxi << endl;
    }
    return 0;
}