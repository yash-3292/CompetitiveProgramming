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
        int p;
        cin >> p;
        p--;
        int i = p;
        int j = p;
        int ans = 0;
        int val = arr[p];
        while(i != 0 || j != n-1){
            while(i != 0 && arr[i-1] == val) i--;
            while(j != n-1 && arr[j+1] == val) j++;
            ans++;
            val = 1-val;
        }
        if(val == arr[p]) ans++;
        ans--;
        cout << ans << endl;
    }
    return 0;
}