#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<ll> preSum(n);
        preSum[0] = (ll)b[0];
        for(int i=1; i<n; i++) preSum[i] = preSum[i-1] + (ll)b[i];
        vector<ll> parcnt(n, 0);
        vector<ll> residue(n, 0);
        for(int i=0; i<n; i++){
            ll prev = 0;
            if(i != 0) prev = preSum[i-1];
            int lo = i;
            int hi = n-1;
            int ansi = -1;
            while(lo <= hi){
                int mid = lo + (hi-lo)/2;
                if(preSum[mid]-prev > (ll)a[i]){
                    ansi = mid;
                    hi = mid-1;
                } else{
                    lo = mid+1;
                }
            }
            parcnt[i]++;
            if(ansi != -1){
                parcnt[ansi]--;
                ll temp = 0;
                if(ansi != 0) temp = preSum[ansi-1]-prev;
                residue[ansi] += (a[i] - temp);
            }
        }
        ll cnt = 0;
        for(int i=0; i<n; i++){
            cnt += parcnt[i];
            ll ans = cnt*(ll)b[i] + residue[i]; 
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}