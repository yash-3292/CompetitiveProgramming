#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> arr(m);
    for(int i=0; i<m; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    vector<int> minend(m);
    minend[m-1] = n+10;
    for(int i=m-2; i>=0; i--){
        minend[i] = min(minend[i+1], arr[i+1].second);
    }
    map<pair<int,int>, int> mppfull;
    for(int i=0; i<m; i++){
        if(i > 0 && arr[i].first == arr[i-1].first) mppfull[{arr[i].first, arr[i].second}] = 1;
        else if(minend[i] <= arr[i].second) mppfull[{arr[i].first, arr[i].second}] = 1;
    } 
    unordered_map<int,vector<int>> mppbegin;
    unordered_map<int,vector<int>> mppend;
    for(int i=0; i<m; i++){
        mppbegin[arr[i].first].push_back(arr[i].second);
        mppend[arr[i].second].push_back(arr[i].first);
    }
    for(auto &it : mppbegin){
        sort(it.second.begin(), it.second.end());
    }
    for(auto &it : mppend){
        sort(it.second.begin(), it.second.end());
    }
    int q;
    cin >> q;
    while(q--){
        int s, t;
        cin >> s >> t;
        int c1 = 0;
        int c2 = 0;
        if(mppfull.find({s,t}) != mppfull.end()) c1 = 1;
        auto end1 = upper_bound(mppbegin[s].begin(), mppbegin[s].end(), t);
        auto begin2 = lower_bound(mppend[t].begin(), mppend[t].end(), s);
        if(end1 != mppbegin[s].begin() && begin2 != mppend[t].end()){
            end1--;
            if(*end1+1 >= *begin2){
                c2 = 1;
            }
            if(*end1 == t) c2 = 0;
        }
        if(c1 || c2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main(){
    solve();
    return 0;
}