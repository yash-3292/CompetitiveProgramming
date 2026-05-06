#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        map<int,int> mpp;
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            if(a[i] == b[i]){
                ans = i+1;
                break;
            }
            if(i == n-1) continue;
            if(a[i] == a[i+1] || b[i] == b[i+1]){
                ans = i+1;
                break;
            }
            if(mpp[a[i]] > 0 || mpp[b[i]] > 0){
                ans = i+1;
                break;
            } 
            mpp[a[i+1]]++;
            mpp[b[i+1]]++;
        }
        cout << ans << endl;
    }
    return 0;
}