#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isAlternate(string s){
    int n = s.size();
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]) return false;
    }
    return true;
}

void f(string s, vector<pair<int,int>>& ans){
    int n = s.size();
    if(isAlternate(s)){
        ans.push_back({1,3});
        for(int i=0; i<3; i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }
    string z(n, '0');
    while(s != z){
        int j;
        for(j=1; j<n; j++){
            if(s[j] == s[j-1]) break;
        }
        int i = j-1;
        while(i > 0 && s[i-1] == s[i]) i--;
        while(j < n-1 && s[j] == s[j+1]) j++;
        ans.push_back({i+1,j+1});
        for(int k=i; k<=j; k++){
            if(s[k] == '0') s[k] = '1';
            else s[k] = '0';
        }
        // cout << s << endl;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;

        vector<pair<int,int>> ans1;
        vector<pair<int,int>> ans2;
        f(s, ans1);
        f(t, ans2);
        reverse(ans2.begin(), ans2.end());
        cout << ans1.size()+ans2.size() << endl;
        for(auto it : ans1) cout << it.first << " " << it.second << endl;
        for(auto it : ans2) cout << it.first << " " << it.second << endl;
    }
    return 0;
}