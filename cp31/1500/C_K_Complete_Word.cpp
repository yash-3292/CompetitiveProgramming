#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int rnd = n/k;
        int ans = 0;
        for(int i=0; i<(k+1)/2; i++){
            vector<int> arr(26,0);
            for(int j=0; j<rnd; j++){
                arr[s[i+j*k]-'a']++;
                if(i != k-i-1) arr[s[k-i-1+j*k]-'a']++;
            }
            int maxi = 0;
            for(int j=0; j<26; j++) maxi = max(maxi, arr[j]);
            if(i != k-i-1) ans += rnd*2 - maxi;
            else ans += rnd - maxi;
        }
        cout << ans << endl;
    }
    return 0;
}