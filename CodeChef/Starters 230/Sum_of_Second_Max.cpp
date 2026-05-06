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
        vector<int> pos(n+1);
        for(int i=0; i<n; i++){
            pos[arr[i]] = i+1;
        }
        ll ans = 0;
        map<int,int> mpp;
        for(int i=n; i>=1; i--){
            auto it = mpp.lower_bound(pos[i]);
            int nge1 = n+1;
            int nge2 = n+1;
            int pge1 = 0;
            int pge2 = 0;
            if(it != mpp.end()){
                nge1 = it->first;
                it++;
                if(it != mpp.end()) nge2 = it->first;
                it--;
            }
            if(it != mpp.begin()){
                it--;
                pge1 = it->first;
                if(it != mpp.begin()){
                    it--;
                    pge2 = it->first;
                }
            }
            ans += ((ll)(pos[i]-pge1) * (ll)(nge2-nge1) + (ll)(pge1-pge2) * (ll)(nge1-pos[i]))*(ll)i;
            mpp[pos[i]] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}