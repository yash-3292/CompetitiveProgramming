#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string temp = s;
        vector<int> arr(n, 0);
        ll ans = 0;
        for(int i=1; i<=n; i++){
            int cnt = 1;
            while((i * cnt) <= n){
                if(temp[i*cnt - 1] == '1') break;
                else{
                    if(arr[i*cnt - 1] == 0){
                        ans += i;
                        arr[i*cnt - 1] = 1;
                    }
                }
                cnt++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}