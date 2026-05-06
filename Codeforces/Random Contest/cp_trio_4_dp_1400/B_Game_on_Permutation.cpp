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
        int mini = n+1;
        int smini = n+1;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i] < mini){
                mini = arr[i];
                continue;
            }
            if(arr[i] < smini){
                ans++;
                smini = arr[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}