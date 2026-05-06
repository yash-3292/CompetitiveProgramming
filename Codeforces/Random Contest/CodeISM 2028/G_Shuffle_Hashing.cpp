#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(vector<int>& passFreq, vector<int>& freq){
    for(int i=0; i<26; i++){
        if(passFreq[i] != freq[i]) return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string p, h;
        cin >> p;
        cin >> h;
        int k = p.size();
        int n = h.size();
        vector<int> passFreq(26, 0);
        for(int i=0; i<k; i++){
            passFreq[p[i]-'a']++;
        }
        vector<int> freq(26, 0);
        int i = 0;
        int j = 0;
        int flag = 0;
        while(j < n){
            freq[h[j]-'a']++;
            if(j-i+1 == k+1){
                freq[h[i]-'a']--;
                i++;
            }
            if(j-i+1 == k){
                if(isPossible(passFreq, freq)){
                    flag = 1;
                    break;
                }
            }
            j++;
        }
        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}