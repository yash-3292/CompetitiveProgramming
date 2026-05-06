#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<int> pos(n+1, 0);
        vector<int> mpp(n+1, 0);
        int flag = 1;
        for(int i=0; i<n; i++){
            if(b[i]!=-1) mpp[b[i]]++;
            if(mpp[b[i]] == 2){
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        for(int i=0; i<n; i++){
            pos[a[i]] = i;
        }
        for(int i=0; i<n; i++){
            if(b[i] != -1){
                int l = min(i, n-k);
                int r = max(i, k-1);
                if(i < n-k) r = i;
                if(i > k-1) l = i;
                if(!(l <= pos[b[i]] && pos[b[i]] <= r)){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}