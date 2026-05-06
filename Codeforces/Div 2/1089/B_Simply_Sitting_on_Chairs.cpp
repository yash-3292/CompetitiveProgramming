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
        int prob = 0;
        int ans = 0;
        vector<int> mpp(n+1, 0);
        for(int i=0; i<n; i++){
            int ind = i+1;
            if(arr[i] > ind){
                mpp[arr[i]] = 1;
            }
            if(mpp[ind]) prob++;
            ans = max(ans, ind-prob);
        }
        cout << ans << endl;
    }
    return 0;
}