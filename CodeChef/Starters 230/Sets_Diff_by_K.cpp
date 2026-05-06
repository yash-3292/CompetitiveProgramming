#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int first = -1;
        int last = -1;
        int flag = 1;
        for(int i=0; i<n; i++){
            if(arr[i]){
                if(last == -1){
                    first = i;
                    last = i;
                    continue;
                }
                if(i-last > 2*(k+1) || i-last <= k){
                    flag = 0;
                    break;
                }
                last = i;
            }
        }
        if(first == -1 || first > k || n-1-last > k){
            flag = 0;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}