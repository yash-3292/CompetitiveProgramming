#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> freq;
        for(int i=0; i<n; i++){
            freq[s[i]]++;
        }
        int ans = 0;
        for(char i='a'; i<='z'; i++){
            if(freq.find(i) != freq.end()){
                ans++;
            }
        }
        int maxi = 0;
        int cnt = 0;
        map<char,int> freq1;
        for(int i=0; i<n; i++){
            if(freq[s[i]] >= 2){
                if(freq1.find(s[i]) == freq1.end()){
                    cnt++;
                }
                freq1[s[i]]++;
                if(freq[s[i]] == freq1[s[i]]){
                    cnt--;
                }
            }
            maxi = max(maxi, cnt);
        }
        ans += maxi;
        cout << ans << endl;
    }
    return 0;
}
