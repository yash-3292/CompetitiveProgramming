#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        map<char, int> freqMap1;
        map<char, int> freqMap2;
        int i = n-1;
        int flag = 1;
        for(int j=m-1; j>=0; j--){
            while(i >= 0){
                if(s[i] != t[j]){
                    freqMap1[s[i]]++;
                    i--;
                } else{
                    break;
                }
            }
            if(i == -1){
                flag = 0;
                break;
            }
            if(freqMap1[s[i]] != freqMap2[s[i]]){
                flag = 0;
                break;
            }
            freqMap1[s[i]]++;
            freqMap2[s[i]]++;
            i--;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}