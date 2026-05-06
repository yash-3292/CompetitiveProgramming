#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int maxi = 0;
        vector<int> arr(n);
        map<int,int> freq;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }
        for(int i=0; i<n; i++){
            int diff = maxi -  arr[i];
            if(diff > 0) freq[diff] = 1;
        }
        int ans = 2*freq.size() + 1;
        cout << ans << endl;
    }
    return 0;
}