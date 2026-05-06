#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, p, m;
        cin >> n >> k >> p >> m;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int fNeed = arr[p-1];
        if(k < p){
            vector<int> temp;
            for(int i=0; i<p-1; i++){
                temp.push_back(arr[i]);
            }
            sort(temp.begin(), temp.end());
            for(int i=0; i<p-k; i++){
                fNeed += temp[i];
            }
        }
        int ans = 0;
        if(fNeed > m){
            cout << 0 << endl;
            continue;
        }
        m -= fNeed;
        ans++;
        int need = arr[p-1];
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(i == p-1) continue;
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end());
        for(int i=0; i<n-k; i++){
            need += temp[i];
        }
        ans += m/need;
        cout << ans << endl;
    }
    return 0;
}