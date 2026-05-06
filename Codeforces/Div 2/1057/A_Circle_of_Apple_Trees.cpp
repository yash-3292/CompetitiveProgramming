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
        map<int,int> mpp;
        for(int i=0; i<n; i++) mpp[arr[i]]++;
        int ans = mpp.size();
        cout << ans << endl;
    }
    return 0;
}