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
        vector<int> diffr(n);
        diffr[0] = -1;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i == 0) continue;
            if(arr[i] != arr[i-1]) diffr[i] = i;
            else diffr[i] = diffr[i-1];
        }
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if(diffr[r] != -1){
                if(diffr[r] - 1 >= l){
                    cout << diffr[r] << " " << diffr[r] + 1 << endl;
                    continue;
                }
            }
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}