#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(26,0);
    for(int i=0; i<n; i++){
        freq[s[i]-'a']++;
    }
    int maxind = -1;
    int minind = -1;
    vector<pair<int,char>> arr;
    for(int i=0; i<26; i++){
        if(freq[i] != 0){
            arr.push_back({freq[i], i+'a'});
        }
    }
    sort(arr.begin(), arr.end());
    if(arr.size() == 1){
        cout << s << endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(s[i] == arr[0].second){
            s[i] = arr.back().second;
            break;
        }
    }
    cout << s << endl;
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