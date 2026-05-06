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
        int cnt = 0;
        if(arr[0] != 0) cnt++;
        for(int i=1; i<n; i++){
            if(arr[i] != 0 && arr[i-1] == 0){
                cnt++;
            }
            if(cnt == 2) break;
        }
        cout << cnt << endl;  
    }
    return 0;
}
