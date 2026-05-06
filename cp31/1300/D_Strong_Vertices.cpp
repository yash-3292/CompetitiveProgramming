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
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, a[i]-b[i]);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(a[i]-b[i] == maxi){
                ans.push_back(i+1);
            }
        }
        cout << ans.size() << endl;
        for(int val : ans){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}