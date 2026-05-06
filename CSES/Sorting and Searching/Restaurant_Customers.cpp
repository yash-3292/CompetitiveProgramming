#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        arr.push_back({x,1});
        arr.push_back({y,-1});
    }
    sort(arr.begin(), arr.end());
    int maxi = 0;
    int cnt = 0;
    for(int i=0; i<2*n; i++){
        cnt += arr[i].second;
        maxi = max(maxi, cnt);
    }
    cout << maxi << endl;
    return 0;
}