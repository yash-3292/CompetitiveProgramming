#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    int sz = (1<<n);
    vector<int> w(n);
    for(int i=0; i<n; i++) cin >> w[i];
    unordered_map<string,int> strToVal;
    for(int i = 0; i <sz; i++){
        string s = bitset<12>(i).to_string().substr(12-n);
        strToVal[s] = i;
    }
    vector<int> cntArr(sz,0);
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        int val = strToVal[s];
        cntArr[val]++;
    }
    vector<int> sumArr(sz);
    for(int i=0; i<sz; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)) sum += w[n-1-j];
        }
        sumArr[i] = sum;
    }
    vector<int> temp;
    for(int i=0; i<sz; i++) if(sumArr[i] < 200) temp.push_back(i);
    vector<vector<int>> arr(sz, vector<int>(200,0));
    for(int i=0; i<sz; i++){
        for(auto j : temp){
            int sumi = sumArr[j];
            if(sumi < 200) arr[i][sumi] += cntArr[((i ^ ((1<<n)-1)) ^ j)];
        }
    }
    for(int i=0; i<sz; i++){
        for(int j=1; j<200; j++){
            arr[i][j] = arr[i][j]+arr[i][j-1];
        }
    }
    for(int i=0; i<q; i++){
        string t;
        int k;
        cin >> t;
        cin >> k;
        int val = strToVal[t];
        int ans = arr[val][k];
        cout << ans << endl;
    }
    return 0;
}