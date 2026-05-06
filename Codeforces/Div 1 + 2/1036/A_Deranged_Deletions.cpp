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
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int ans = -1;
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                ans = i;
                break;
            }
        }
        if(ans != -1){
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << arr[ans] << " " << arr[ans+1] << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}