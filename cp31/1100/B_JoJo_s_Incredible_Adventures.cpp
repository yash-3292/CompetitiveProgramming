#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int isAllOne = 1;
        for(int i=0; i<n; i++){
            if(s[i] == '0') isAllOne = 0;
        }
        if(isAllOne){
            ll total = (ll)n * (ll)n;
            cout << total << endl;
            continue;
        }
        int cnt = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') cnt++;
            else cnt = 0;
            maxi = max(maxi, cnt);
        }
        for(int i=0; i<n; i++){
            if(s[i] == '1') cnt++;
            else cnt = 0;
            maxi = max(maxi, cnt);
        }
        maxi++;
        ll size;
        if(maxi & 1) size = (ll)(maxi/2) * (ll)(maxi/2 + 1);
        else size = (ll)(maxi/2) * (ll)(maxi/2);
        cout << size << endl;
    }
    return 0;
}