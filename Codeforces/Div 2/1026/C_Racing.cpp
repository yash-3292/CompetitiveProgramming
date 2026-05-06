#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> d(n);
        for(int i=0; i<n; i++) cin >> d[i];
        vector<pair<int,int>> h(n+1);
        h[0].first = 0;
        h[0].second = 0;
        for(int i=1; i<=n; i++) cin >> h[i].first >> h[i].second;
        vector<pair<int,int>> arr(n+1);
        arr[n] = h[n];
        int flag = 1;
        for(int i=n-1; i>=0; i--){
            int l = arr[i+1].first;
            int r = arr[i+1].second;
            if(d[i] == 1){
                l--; r--;
            } else if(d[i] == -1){
                l--;
            }
            l = max(l, h[i].first);
            r = min(r, h[i].second);
            if(l > r){
                flag = 0;
                break;
            }
            arr[i].first = l;
            arr[i].second = r;
        }
        if(!flag){
            cout << -1 << endl;
            continue;
        }
        int val = 0;
        for(int i=1; i<=n; i++){
            if(d[i-1] == 1){
                val++;
            } else if(d[i-1] == -1){
                if(arr[i].second != val){
                    d[i-1] = 1;
                    val++;
                } else{
                    d[i-1] = 0;
                }
            }
        }
        for(auto it : d) cout << it << " ";
        cout << endl;
    }
    return 0;
}