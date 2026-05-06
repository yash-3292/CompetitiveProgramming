#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        l--;r--;
        vector<int> pref(n);
        for(int i=0; i<n; i++) pref[i] = i+1;
        if(l != 0) pref[r] = pref[l-1];
        else pref[r] = 0;
        cout << pref[0] << " ";
        for(int i=1; i<n; i++){
            int x = (pref[i]^pref[i-1]);
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}