#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxCommonLength(string s, string t){
    int n = s.size();
    int m = t.size();
    int maxi = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i] == t[j]){
                int cnt = 0;
                int p1 = i, p2 = j;
                while(p1 < n && p2 < m){
                    if(s[p1] != t[p2]) break;
                    cnt++;
                    p1++;
                    p2++;
                }
                maxi = max(maxi, cnt);
            }
        }
    }
    return maxi;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        int maxLength;
        int n = s.size();
        int m = t.size();
        if(n <= m){
            maxLength = maxCommonLength(s, t);
        } else{
            maxLength = maxCommonLength(t, s);
        }
        int ans = n + m - 2*maxLength;
        cout << ans << endl;
    }
    return 0;
}
