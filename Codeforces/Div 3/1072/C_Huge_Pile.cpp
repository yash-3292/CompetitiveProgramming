#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        int ans = -1;
        int temp = n;
        if(temp == 1 && k == 1) ans = 0;
        while(temp != 1){
            if(temp == k){
                ans = cnt;
                break;
            }
            if(temp&1){
                if(k == temp/2 || k == temp/2 + 1){
                    ans = cnt+1;
                    break;
                }
                temp = temp/2;
                if(temp%2==0) temp++;
            } else{
                if(k == temp/2){
                    ans = cnt+1;
                    break;
                }
                temp = temp/2;
            }
            cnt++;
        }
        cout << ans << endl;
    }
    return 0;
}