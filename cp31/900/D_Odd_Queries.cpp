#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        vector<int> sumArr(n);
        cin >> arr[0];
        sumArr[0] = arr[0] & 1;
        for(int i=1; i<n; i++){
            cin >> arr[i];
            sumArr[i] = (sumArr[i-1]+arr[i]) & 1;
        }
        while(q--){
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            int rangeSum;
            if(l != 0) rangeSum = abs(sumArr[l-1] - sumArr[r]);
            else rangeSum = sumArr[r];
            k = k & 1;
            if(k) k = (r-l+1)&1;
            int flag;
            if(k == rangeSum) flag = sumArr[n-1];
            else flag = abs(sumArr[n-1] - 1);
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
