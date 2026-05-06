#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int k, int m, vector<pair<int,int>>& arr){
    if(i < 0 || k < 0) return 0;

    int ans = 0;
    for(int j=0; j<=arr[i].second; i++){
        int val = 
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> temp(n);
        for(int i=0; i<n; i++) cin >> temp[i];
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            if(temp[i] == 0) continue;
            if(arr.size() == 0){
                arr.push_back({i, temp[i]});
            } else if(arr.back().second < temp[i]){
                arr.push_back({i, temp[i]});
            }
        }
        int m = arr.size();
        
    }
    return 0;
}