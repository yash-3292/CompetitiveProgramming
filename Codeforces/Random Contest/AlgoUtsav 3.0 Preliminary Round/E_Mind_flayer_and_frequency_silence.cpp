#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        map<int,vector<int>> mpp;
        int ans = 0;
        int x = 0;
        mpp[0].push_back(0);
        for(int i=0; i<n; i++){
            x = (x^arr[i]);
            if(mpp.find(x) != mpp.end()){
                int j = mpp[x][0];
                j++;
                ans = max(ans, i+1-j+1);
            }
            mpp[x].push_back(i+1);
        }
        for(int i=0; i<n; i++){
            x = (x^arr[i]);
            if(mpp.find(x) != mpp.end()){
                auto it = upper_bound(mpp[x].begin(), mpp[x].end(), i);
                if(it == mpp[x].end()) continue;
                int pos = it - mpp[x].begin();
                int j = mpp[x][pos];
                j++;
                ans = max(ans, n-j+i+1+1);
                // cout << i << " " << j << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}