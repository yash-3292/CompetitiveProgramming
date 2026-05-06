#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int ans = INT_MAX;
        if(n >= m){
            for(int j1=0; j1<m; j1++){
                for(int j2=j1+1; j2<m; j2++){
                    int x = -1;
                    for(int i=0; i<n; i++){
                        if(arr[i][j1] == '1' && arr[i][j2] == '1'){
                            if(x != -1){
                                ans = min(ans, (i-x+1)*(j2-j1+1));
                            } 
                            x = i;
                        }
                    }
                }
            }
        } else{
            for(int i1=0; i1<n; i1++){
                for(int i2=i1+1; i2<n; i2++){
                    int x = -1;
                    for(int j=0; j<m; j++){
                        if(arr[i1][j] == '1' && arr[i2][j] == '1'){
                            if(x != -1){
                                ans = min(ans, (j-x+1)*(i2-i1+1));
                            } 
                            x = j;
                        }
                    }
                }
            }
        }
        if(ans == INT_MAX){
            cout << 0 << endl;
        } else{
            cout << ans << endl;
        }
    }
    return 0;
}