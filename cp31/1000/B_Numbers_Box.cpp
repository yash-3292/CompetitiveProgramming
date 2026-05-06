#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int sum = 0;
        int mini = 200;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int num; 
                cin >> num;
                sum += abs(num);
                if(num < 0) cnt++;
                mini = min(mini, abs(num));
            }
        }
        int ans;
        if(cnt & 1) ans = sum - 2*mini;
        else ans = sum;
        cout << ans << endl;
    }
    return 0;
}
