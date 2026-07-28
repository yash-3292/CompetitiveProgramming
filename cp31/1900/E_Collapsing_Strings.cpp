#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 2e6+10;
int val1[maxN];
int val2[maxN];
vector<map<int,int>> mpp(maxN);
int sz = 1;

// struct t {
//     unordered_map<int,t*> mpp;
//     int val1;
//     int val2;
//     t(){
//         val1 = 0;
//         val2 = 0;
//     }
// };

class Trie {
public: 
    int root;
    Trie() {
        root = 0;
        val1[root] = 0;
        val2[root] = 0;
    }
    void insert1(string& word){
        int temp = root;
        for(auto ch : word){
            int val = ch - 'a';
            if(mpp[temp].find(val) == mpp[temp].end()){
                mpp[temp][val] = sz;
                sz++;
                temp = mpp[temp][val];
                val1[temp] = 0;
                val2[temp] = 0;
            } else{
                temp = mpp[temp][val];
            }
            val1[temp]++;
        }
    }
    void insert2(string& word){
        reverse(word.begin(), word.end());
        int temp = root;
        for(auto ch : word){
            int val = ch - 'a';
            if(mpp[temp].find(val) == mpp[temp].end()){
                mpp[temp][val] = sz;
                sz++;
                temp = mpp[temp][val];
                val1[temp] = 0;
                val2[temp] = 0;
            } else{
                temp = mpp[temp][val];
            }
            val2[temp]++;
        }
    }
    ll dfs(int temp){
        // cout << val1[temp] << " " << val2[temp] << endl;
        ll ans = (ll)val1[temp] * (ll)val2[temp];
        for(int i=0; i<26; i++){
            if(mpp[temp].find(i) != mpp[temp].end()){
                ans += dfs(mpp[temp][i]);
            }
        }
        return ans;
    }
    ll f(){
        int temp = root;
        return dfs(temp);
    }
};

void solve(){
    int n;
    cin >> n;
    Trie tr;
    ll total = 0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        total += s.size();
        tr.insert1(s);
        tr.insert2(s);
    }
    ll ans = (ll)2*(ll)total*(ll)n;
    ans -= 2*tr.f();
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}