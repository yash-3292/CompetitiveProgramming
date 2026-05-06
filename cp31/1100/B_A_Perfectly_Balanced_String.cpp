#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        map<char,int> freq;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(freq[s[i]] == 0) cnt++;
            freq[s[i]] = 1;
        }
        freq.clear();
        int flag = 1;
        for(int i=0; i<cnt; i++){
            if(freq[s[i]] > 0){
                flag = 0;
                break;
            } 
            freq[s[i]] = 1;
        }
        for(int i=cnt; i<n; i++){
            if(s[i] != s[i-cnt]){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}