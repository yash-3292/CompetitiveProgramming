#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<int> sum(n);
        vector<int> maxi(n);
        sum[0] = a[0];
        maxi[0] = b[0];
        for(int i=1; i<n; i++){
            sum[i] = sum[i-1] + a[i];
            maxi[i] = max(maxi[i-1], b[i]);
        }
        int maxii = 0;
        for(int i=0; i<n && i<k; i++){
            int val = sum[i] + (k - i - 1)*maxi[i];
            maxii = max(maxii, val);
        }
        cout << maxii << endl;
    }
    return 0;
}