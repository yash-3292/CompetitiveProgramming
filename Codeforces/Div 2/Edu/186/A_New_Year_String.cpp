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
        int flag1 = 0;
        int flag2 = 0;
        for(int i=0; i<=n-4; i++){
            if(s.substr(i, 4) == "2026") flag1 = 1;
            else if(s.substr(i, 4) == "2025") flag2 = 1;
        }
        int ans = 0;
        if((!flag1) && flag2) ans = 1;
        cout << ans << endl;
    }
    return 0;
}