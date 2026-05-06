#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int n, unordered_map<int,int>& mpp){
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            mpp[i] = 1;
            mpp[n/i] = 1;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        int ans = 0;
        for(int i=0; i<n; i++){
            int val;
            if(i == 0){
                val = __gcd(a[i], a[i+1]);
            } else if(i == n-1){
                val = __gcd(a[i], a[i-1]);
            } else{
                int gcd1 = __gcd(a[i], a[i+1]);
                int gcd2 = __gcd(a[i], a[i-1]);
                val = (gcd1/__gcd(gcd1, gcd2)) * gcd2;
            }
            if(val <= b[i] && val != a[i]){
                ans++;
                a[i] = val;
            } else if(a[i] < b[i]){
                unordered_map<int,int> mpp;
                if(i != 1) f(a[i-1], mpp);
                if(i != n-1) f(a[i+1], mpp);
                for(int j=b[i]/a[i]; j>1; j--){
                    int d = j * a[i];
                    if(mpp.find(d) == mpp.end()){
                        ans++;
                        a[i] = d;
                        break;
                    }
                }
            }
        }
        for(auto it : a) cout << it << " ";
        cout << endl;
        cout << ans << "\n";
    }
    return 0;
}