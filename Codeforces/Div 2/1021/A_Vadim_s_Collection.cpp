#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n = 10;
    string s;
    cin >> s;
    vector<int> freq(n, 0);
    for(int i=0; i<n; i++) freq[s[i]-'0']++;
    for(int i=0; i<n; i++){
        int thres = 10-i-1;
        for(int j=thres; j<n; j++){
            if(freq[j]){
                cout << j;
                freq[j]--;
                break;
            }
        }
    } 
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}