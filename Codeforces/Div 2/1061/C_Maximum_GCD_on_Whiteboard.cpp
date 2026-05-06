#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> cnt(n+10,0);
        for(int i=0; i<n; i++){
            int temp = arr[i]/4;
            cnt[1]++;
            cnt[temp+1]--;
            cnt[arr[i]]++;
            cnt[arr[i]+1]--;
            if(arr[i]%2 == 0){
                cnt[arr[i]/2]++;
                cnt[arr[i]/2+1]--;
            }
            if(arr[i]%3 == 0){
                cnt[arr[i]/3]++;
                cnt[arr[i]/3+1]--;
            }
        }
        int ans = 1;
        for(int i=1; i<n+10; i++){
            cnt[i] += cnt[i-1];
            if(cnt[i] >= n-k) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}