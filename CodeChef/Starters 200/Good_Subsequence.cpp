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
        int val = arr[0];
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i]%2 != val%2){
                cnt++;
                val = arr[i];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}