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
        int maxi = abs(arr[0]-arr[1]);
        int ind = 0;
        if(abs(arr[n-1]-arr[n-2]) > maxi){
            maxi = abs(arr[n-1]-arr[n-2]);
            ind = n-1;
        }
        for(int i=1; i<n-1; i++){
            int val = abs(arr[i-1]-arr[i]) + abs(arr[i]-arr[i+1]) - abs(arr[i-1]-arr[i+1]);
            if(val > maxi){
                ind = i;
                maxi = val;
            }
        }
        arr.erase(arr.begin() + ind);
        int ans = 0;
        for(int i=1; i<n-1; i++){
            ans += abs(arr[i]-arr[i-1]);
        }
        cout << ans << endl;
    }
    return 0;
}