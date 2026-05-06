#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int k;
        cin >> s >> k;
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        string t;
        for(int i=0; i<26; i++){
            if(freq[i] == 0){
                t += i+'a';
            } else{
                if(k){
                    k--;
                    t += i+'a';
                }
            }
        }
        if(t.size() < n){
            cout << "NOPE" << endl;
            continue;
        } 
        for(int i=0; i<n; i++){
            cout << t[i];
        }
        cout << endl;
    }
    return 0;
}