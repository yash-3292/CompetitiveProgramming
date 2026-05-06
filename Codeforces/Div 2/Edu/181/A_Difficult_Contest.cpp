#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string ans;
        unordered_map<char,int> mpp;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == 'T' || s[i] == 'N' || s[i] == 'F'){
                mpp[s[i]]++;
            } else{
                ans += s[i];
            }
        }
        while(mpp['T']){
            ans += 'T';
            mpp['T']--;
        }
        while(mpp['N']){
            ans += 'N';
            mpp['N']--;
        }
        while(mpp['F']){
            ans += 'F';
            mpp['F']--;
        }
        cout << ans << endl;
    }
    return 0;
}