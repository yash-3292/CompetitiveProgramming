#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h;
        ll maxi = 0;
        for(int i=0; i<2; i++){
            int n;
            cin >> n;
            vector<int> arr(n);
            for(int j=0; j<n; j++) cin >> arr[j];
            maxi = max(maxi, (ll)(arr[n-1]-arr[0])*(ll)h);
        }
        for(int i=0; i<2; i++){
            int n;
            cin >> n;
            vector<int> arr(n);
            for(int j=0; j<n; j++) cin >> arr[j];
            maxi = max(maxi, (ll)(arr[n-1]-arr[0])*(ll)w);
        }
        cout << maxi << endl;
    }
    return 0;
}
