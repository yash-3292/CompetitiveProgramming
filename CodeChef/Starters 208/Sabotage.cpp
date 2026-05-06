#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, k;
        cin >> n >> x >> k;
        x += k*100;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int r = 0;
        for(int i=0; i<n-k; i++){
            if(arr[i] > x) r++;
        }
        r++;
        cout << r << endl;
    }
    return 0;
}