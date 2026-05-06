#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string t;
        cin >> t;
        vector<int> freqs(26, 0);
        vector<int> freqt(26, 0);
        for(auto ch : s) freqs[ch-'a']++;
        for(auto ch : t) freqt[ch-'a']++;
        int flag = 1;
        string x;
        for(int i=0; i<26; i++){
            if(freqs[i] > freqt[i]){
                flag = 0;
                break;
            } 
            freqt[i] -= freqs[i];
            while(freqt[i] != 0){
                x += i+'a';
                freqt[i]--;
            }
        }
        if(!flag){
            cout << "Impossible" << endl;
            continue;
        }
        int n = x.size();
        int m = s.size();
        int i = 0;
        int j = 0;
        string ans;
        while(i < n && j < m){
            if(x[i] < s[j]){
                ans += x[i];
                i++;
            } else{
                ans += s[j];
                j++;
            }
        }
        while(i < n){
            ans += x[i];
            i++;
        }
        while(j < m){
            ans += s[j];
            j++;
        }
        cout << ans << endl;
    }
    return 0;
}