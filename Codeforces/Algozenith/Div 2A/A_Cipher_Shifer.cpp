#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        string ans;
        int i = 0;
        while(i < n){
            ans += s[i];
            int j = i+1;
            while(s[j] != s[i]) j++;
            i = j+1;
        }
        cout << ans << endl;
    }
    return 0;
}
