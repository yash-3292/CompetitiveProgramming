#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k; 
        string s;
        cin >> s;
        int cnt = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                cnt = k;
            } else{
                if(cnt){
                    cnt--;
                } else{
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}