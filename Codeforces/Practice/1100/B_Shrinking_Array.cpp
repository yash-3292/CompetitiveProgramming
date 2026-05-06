#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int flag = 0;
        for(int i=0; i<n-1; i++){
            if(abs(arr[i]-arr[i+1]) <= 1){
                flag = 1;
                break;
            }
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        if(is_sorted(arr.begin(), arr.end())){
            cout << -1 << endl;
            continue;
        } 
        reverse(arr.begin(), arr.end());
        if(is_sorted(arr.begin(), arr.end())){
            cout << -1 << endl;
            continue;
        } 
        cout << 1 << endl;
    }
    return 0;
}