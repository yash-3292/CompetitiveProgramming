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
        int flag = 1;
        for(int i=0; i<n; i++){
            int x = i+1;
            int y = arr[i];
            if(x > y) swap(x,y);
            int f = 0;
            while(y > 0){
                if(x == y){
                    f = 1;
                    break;
                }
                if(y&1) break;
                y >>= 1;
            }
            if(!f){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}