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
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mini = min(arr[i], mini);
            maxi = max(arr[i], maxi);
        } 
        int x;
        cin >> x; 
        if(maxi < x || x < mini){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
    return 0;
}