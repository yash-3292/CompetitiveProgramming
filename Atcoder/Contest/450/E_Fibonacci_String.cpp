#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n, ll ch, vector<ll>& len, vector<vector<ll>>& freq, vector<vector<ll>>& preSum){
    if(n == 0) return 0;
    auto it = upper_bound(len.begin(), len.end(), n);
    it--;
    int ind = it-len.begin();
    if(ind < 2){
        return preSum[n][ch];
    }
    return freq[ind][ch] + f(n-len[ind], ch, len, freq, preSum);
}

int main(){
    string x, y;
    cin >> x >> y;
    vector<ll> len;
    vector<vector<ll>> freq;
    len.push_back(x.size());
    len.push_back(y.size());
    vector<ll> freq1(26, 0);
    for(auto ch : x){
        freq1[ch-'a']++;
    }
    freq.push_back(freq1);
    vector<ll> freq2(26, 0);
    for(auto ch : y){
        freq2[ch-'a']++;
    }
    freq.push_back(freq2);
    while(true){
        int n = len.size();
        if(len[n-1]+len[n-2] > (ll)1e18) break;
        len.push_back(len[n-1]+len[n-2]);
        vector<ll> freqt(26,0);
        for(ll i=0; i<26; i++){
            freqt[i] = freq[n-1][i] + freq[n-2][i];
        }
        freq.push_back(freqt);
    }
    string z = y+x;
    vector<vector<ll>> preSum(z.size(), vector<ll>(26,0));
    preSum[0][z[0]-'a']++;
    for(ll i=1; i<z.size(); i++){
        for(ll j=0; j<26; j++) preSum[i][j] = preSum[i-1][j];
        preSum[i][z[i]-'a']++;
    }
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        char c;
        cin >> l >> r >> c;
        ll ch = c-'a';
        ll ans = f(r, ch, len, freq, preSum);
        if(l > 0) ans -= f(l-1, ch, len, freq, preSum);
        cout << ans << endl;
    }
    return 0;
}