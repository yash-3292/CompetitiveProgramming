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
        sort(arr.begin(), arr.end());
        int ans = 0;
        int currSet = 0;
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i] != arr[i-1]){
                if(currSet < cnt){
                    ans += cnt - currSet;
                    currSet = cnt;
                } else{
                    currSet = cnt;
                }
                cnt = 1;
                if(arr[i] - arr[i-1] >= 2) currSet = 0;
            } 
            else cnt++;
        }
        if(currSet < cnt){
            ans += cnt - currSet;
            currSet = cnt;
        } else{
            currSet = cnt;
        }
        cout << ans << endl;
    }
    return 0;
}