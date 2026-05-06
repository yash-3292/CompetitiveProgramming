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
        int p = -1, q = -1;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]%2 == 0){
                if(p == -1) p = i;
                else if(q == -1) q = i;
            }
        }
        if(p != -1 && q != -1){
            cout << arr[p] << " " << arr[q] << endl;
            continue; 
        } 
        if(p != -1){
            int x = arr[p];
            arr.erase(arr.begin()+p);
            n = arr.size();
            int ans = -1;
            for(int i=0; i<n; i++){
                if(x > arr[i] && ((x%arr[i])%2 == 0)){
                    ans = arr[i];
                }
            }
            if(ans != -1){
                cout << ans << " " << x << endl;
                continue;
            }
        }
        int flag = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((arr[j]%arr[i])%2 == 0){
                    cout << arr[i] << " " << arr[j] << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag){
            cout << -1 << endl;
        }
    }
    return 0;
}