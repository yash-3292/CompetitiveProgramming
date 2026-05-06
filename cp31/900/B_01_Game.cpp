#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int zero = 0;
        int one = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') zero++;
            else one++;
        }
        int ans = min(zero, one);
        if(ans&1) cout << "DA" << endl;
        else cout << "NET" << endl;
    }
    return 0;
}