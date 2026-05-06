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
        int i = n-2;
        int same = 1;
        int ans = 0;
        for(int i=n-2; i>=0;){
            if(arr[i] == arr[n-1]){
                same++;
                i--;
            } 
            else{
                if(i+1 >= same) i -= same;
                else i = -1;
                same *= 2;
                ans++;
            }
            if(i < 0) break;
        }
        cout << ans << endl;
    }
    return 0;
}