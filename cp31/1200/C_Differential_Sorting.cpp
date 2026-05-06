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
        int sorted = 1;
        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1]){
                sorted = 0;
                break;
            }
        }
        if(sorted){
            cout << 0 << endl;
            continue;
        }
        if(arr[n-2] > arr[n-1]){
            cout << -1 << endl;
            continue;
        }
        if(arr[n-1] < 0){
            cout << -1 << endl;
            continue;
        }
        cout << n-2 << endl;
        for(int i=1; i<=n-2; i++){
            cout << i << " " << n-1 << " " << n << endl;
        }
    }
    return 0;
}