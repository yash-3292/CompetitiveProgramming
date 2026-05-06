#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        ll sum = 0;
        ll ans = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum += (ll)arr[i];
        }
        sort(arr.begin(), arr.end());
        int i=0;
        int j = n-1;
        while(i <= j){
            if(sum == 1){
                ans++;
                break;
            }
            if((ll)arr[j] > (sum/2)){
                ans += sum/2+1;
                if(sum&1) ans++;
                break;
            }
            int cnt = arr[j];
            ans += (ll)(cnt) + 1;
            sum -= ((ll)(cnt))*2;
            j--;
            while(cnt){
                if(arr[i] > cnt){
                    arr[i] -= cnt;
                    cnt = 0;
                } else{
                    cnt -= arr[i];
                    i++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}