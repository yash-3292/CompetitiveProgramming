#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        map<char, int> freq;
        for(int i=0; i<n; i++){
            if(freq[s[i]] == 0){
                cnt += n - i;
                freq[s[i]]++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}