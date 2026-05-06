#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, p;
        cin >> n >> p;
        vector<pair<int,int>> CostResident(n);
        for(int i=0; i<n; i++) cin >> CostResident[i].second;
        for(int i=0; i<n; i++) cin >> CostResident[i].first;
        int cnt = n-1;
        ll total = (ll)p;
        sort(CostResident.begin(), CostResident.end());
        int i=0;
        while(cnt > 0){
            if(CostResident[i].first > p) break;
            if(CostResident[i].second <= cnt){
                total += (ll)CostResident[i].second*(ll)CostResident[i].first;
                cnt -= CostResident[i].second;
            } else{
                total += (ll)cnt*(ll)CostResident[i].first;
                cnt = 0;
            }
            i++;
        }
        total += (ll)cnt*(ll)p;
        cout << total << endl;
    }
    return 0;
}
