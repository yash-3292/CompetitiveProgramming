#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 2019;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> powerTen(n);
    powerTen[0] = 1;
    for(int i=1; i<n; i++){
        powerTen[i] = (powerTen[i-1] * 10) % mod; 
    }
    vector<int> freq(2019, 0);
    freq[0]++;
    int val = 0;
    ll cnt = 0;
    for(int i=0; i<n; i++){
        val = (val * 10 + (s[i]-'0')) % mod;
        int x = (val * powerTen[n-i-1]) % mod;
        cnt += (ll)freq[x];
        freq[x]++;
    }
    cout << cnt << endl;
    return 0;
}