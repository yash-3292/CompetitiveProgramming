#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPallindrome(string& s){
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

int f(int ind1, string& s){
    int n = s.size();
    vector<int> freq1(26,0);
    vector<int> freq2(26,0);
    for(int i=ind1; i<n/2; i++){
        int j = n-i-1;
        freq1[s[i]-'a']++;
        freq2[s[j]-'a']++;
    }
    for(int i=n/2; i<n-ind1-1; i++){
        freq1[s[i]-'a']++;
        freq2[s[i]-'a']--;
        bool flag = true;
        for(int j=0; j<26; j++){
            if(freq1[j] < freq2[j]){
                flag = false;
                break;
            }
            if((freq1[j] - freq2[j]) % 2 != 0){
                flag = false;
                break;
            }
        }
        if(flag){
            return i - ind1 + 1; 
        }
    }
    return -1;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(isPallindrome(s)){
        cout << 0 << endl;
        return;
    }
    int ind1 = -1, ind2 = -1;
    for(int i=0; i<n/2; i++){
        if(s[i] != s[n-i-1]){
            ind1 = i;
            break;
        }
    }
    for(int i=n/2-1; i>=0; i--){
        if(s[i] != s[n-i-1]){
            ind2 = i;
            break;
        }
    }
    vector<int> freq1(26,0);
    vector<int> freq2(26,0);
    for(int i=ind1; i<=ind2; i++){
        int j = n-i-1;
        freq1[s[i]-'a']++;
        freq2[s[j]-'a']++;
    }
    if(freq1 == freq2){
        cout << ind2 - ind1 + 1 << endl;
        return;
    }
    int ans = f(ind1, s);
    reverse(s.begin(), s.end());
    ans = min(ans, f(ind1, s));
    cout << ans << endl;
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