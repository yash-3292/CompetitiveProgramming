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
        vector<int> prev(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            prev[i] = i;
        }
        int thres = 1;
        for(int i=0; i<n; i++){
            int val = i+arr[i]-1;
            val = min(val, n-1);
            for(int j=thres; j<=val; j++){
                prev[j] = i;
            }
            thres = val+1;
            if(thres == n) break;
        }
        for(int i=0; i<n; i++){
            int ans = i-prev[i]+1;
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}