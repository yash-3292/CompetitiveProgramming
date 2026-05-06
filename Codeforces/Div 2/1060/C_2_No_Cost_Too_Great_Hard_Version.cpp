#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int sz = 1e6;
vector<int> spf(sz);

void pre(){
    for(int i=0; i<sz; i++) spf[i] = i;
    for(int i=2; i<sz; i++){
        if(spf[i] == i){
            for(int j=2*i; j<sz; j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

void f(int n, int cost, unordered_map<int, pair<int,int>>& mpp){
    int temp = n;
    while(temp > 1){
        int factor = spf[temp];

        if(mpp.find(factor) == mpp.end()) mpp[factor] = {cost, -1};
        else if(mpp[factor].second == -1) mpp[factor].second = cost;
        else{
            if(cost < mpp[factor].first) mpp[factor].first = cost;
            else if(cost < mpp[factor].second) mpp[factor].second = cost;
        }

        while(temp%factor == 0) temp /= factor;
    }
}

int main(){
    pre();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        unordered_map<int, pair<int,int>> mpp;
        for(int i=0; i<n; i++){
            f(a[i], 0, mpp);
            f(a[i]+1, b[i], mpp);
        }
    }
    return 0;
}