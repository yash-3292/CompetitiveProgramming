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
        int maxi = arr[0];
        int cnt = 0;
        if(arr[0] > 0) cnt += arr[0];
        for(int i=1; i<n; i++){
            if(abs(arr[i]%2) != abs(arr[i-1]%2)){
                cnt += arr[i];
            } else{
                cnt = arr[i];
            }
            maxi = max(maxi, cnt);
            if(cnt < 0) cnt = 0;
        } 
        cout << maxi << endl;
    }
    return 0;
}