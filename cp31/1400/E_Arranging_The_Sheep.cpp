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
        vector<int> arr(n,0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '*') cnt++;
            else arr[i] = cnt;
        }
        cnt = 0;
        ll ans = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '*') cnt++;
            else{
                ans += (ll)min(cnt, arr[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}