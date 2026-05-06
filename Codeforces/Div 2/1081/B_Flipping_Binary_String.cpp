#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(string& s, int z, int o, int n, vector<int>& ans){
    if(z == n){
        return;
    }
    if((n-z)%2 == 0 && z+1 != o){
        int cnt = n-z;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ans.push_back(i);
                cnt--;
            }
            if(!cnt) break;
        }
        if(cnt) ans = {1};
    } else if(z > 0 && (n-o)%2 != 0 && z != o+1){
        int i = 0;
        while(s[i] != '0') i++;
        // cout << "hi";
        ans.push_back(i);
        for(int j=0; j<n; j++){
            if(j != i){
                if(s[j] == '0') s[j] = '1';
                else s[j] = '0';
            } 
        }
        // cout << s;
        f(s, o+1, z-1, n, ans);
    } else{
        ans.push_back(-1);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int z = count(s.begin(), s.end(), '0');
        int o = n - z;
        vector<int> ans;
        f(s, z, o, n, ans);
        if(!ans.size()) cout << 0 << endl;
        else if(ans[0] == -1) cout << -1 << endl;
        else{
            cout << ans.size() << endl;
            for(auto it : ans) cout << it+1 << " ";
            cout << endl;
        }
    }
    return 0;
}