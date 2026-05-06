#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        arr.push_back({x,1});
        arr.push_back({y+1,-1});
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int flag = 1;
    for(auto it : arr){
        cnt += it.second;
        if(cnt > 2){
            flag = 0;
            break;
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}