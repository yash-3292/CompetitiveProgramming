#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++) arr[i] = s[i-1] - '0';
        map<int,int> mpp;
        int sum = 0;
        ll ans = 0;
        for(int i=0; i<=n; i++){
            if(i != 0){
                sum += arr[i];
                if(mpp.find(sum-i) != mpp.end()) ans += (ll)mpp[sum-i];
            }
            mpp[sum-i]++;
        }
        cout << ans << endl;
    }
    return 0;
}