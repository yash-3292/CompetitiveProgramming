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
        vector<int> temp;
        for(int i=0; i<n; i++){
            int j = (i+1)%n;
            temp.push_back(max(arr[i], arr[j]));
        }
        sort(temp.begin(), temp.end());
        ll ans = 0;
        int m = temp.size();
        for(int i=0; i<m-1; i++){
            ans += (ll)temp[i];
        }
        cout << ans << endl;
    }
    return 0;
}