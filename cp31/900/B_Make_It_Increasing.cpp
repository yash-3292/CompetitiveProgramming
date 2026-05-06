#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        if(arr[n-1] == 0){
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        for(int i=n-2; i>=0; i--){
            while(arr[i] >= arr[i+1] && arr[i] != 0){
                arr[i] /= 2;
                cnt++;
            }
            if(arr[i] == 0 && i!=0){
                cnt = -1;
                break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}