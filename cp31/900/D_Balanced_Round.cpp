#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int maxi = 1;
        int total = 1;
        for(int i=1; i<n; i++){
            if(arr[i]-arr[i-1] <= k){
                total++;
            } else{
                total = 1;
            }
            maxi = max(maxi, total);
        }
        cout << n - maxi << endl;
    }
    return 0;
}