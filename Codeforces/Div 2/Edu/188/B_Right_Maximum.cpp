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
        vector<int> maxi(n);
        maxi[0] = 0;
        for(int i=1; i<n; i++){
            if(arr[i] >= arr[maxi[i-1]]){
                maxi[i] = i;
            } else{
                maxi[i] = maxi[i-1];
            }
        }
        int i = n-1;
        int ans = 0;
        while(i >= 0){
            ans++;
            i = maxi[i];
            i--;
        }
        cout << ans << endl;
    }
    return 0;
}