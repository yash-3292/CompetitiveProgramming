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
        sort(arr.begin(), arr.end());
        int i = n-1;
        while(arr[0]%2 != arr[i]%2){
            i--;
        }
        int ans1 = n-1-i;
        i=0;
        while(arr[n-1]%2 != arr[i]%2){
            i++;
        }
        int ans2 = i;
        int ans = min(ans1, ans2);
        cout << ans << endl;
    }
    return 0;
}