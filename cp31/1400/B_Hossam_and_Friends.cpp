#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        map<int,int> mpp;
        for(int i=1; i<=n; i++){
            mpp[i] = n+1;
        }
        while(m--){
            int x, y;
            cin >> x >> y;
            int a = min(x,y);
            int b = max(x,y);
            mpp[a] = min(mpp[a], b);
        }
        ll sum = 0;
        for(int i=n-1; i>=1; i--){
            mpp[i] = min(mpp[i+1], mpp[i]);
        }
        for(int i=1; i<=n; i++){
            sum += (ll)(mpp[i]-i);
        }
        cout << sum << endl;
    }
}