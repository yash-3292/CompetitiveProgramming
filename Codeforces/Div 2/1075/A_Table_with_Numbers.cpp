#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, h, l;
        cin >> n >> h >> l;
        int mini = min(h,l);
        int maxi = max(h,l);
        int x = 0;
        int y = 0;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            if(a <= mini) x++;
            else if(a <= maxi) y++;
        }
        int ans;
        if(x >= y){
            ans = y + (x-y)/2;
        } else{
            ans = x;
        }
        cout << ans << endl;
    }
    return 0;
}