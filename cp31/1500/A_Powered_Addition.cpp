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
        int thres = arr[0];
        int ans = 0;
        for(int i=1; i<n; i++){
            if(arr[i] >= thres) thres = arr[i];
            else ans = max(ans, thres-arr[i]);
        }
        int i;
        for(i=31; i>=0; i--){
            if(ans&(1<<i)){
                break;
            }
        }
        i++;
        cout << i << endl;
    }
    return 0;
}