#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> temp(n);
    for(int i=0; i<n; i++) cin >> temp[i].first >> temp[i].second; 
    vector<int> arr(n-1);
    for(int i=0; i<n-1; i++){
        arr[i] = abs(temp[i].first-temp[i+1].first) + abs(temp[i].second-temp[i+1].second);
    }
    int m = arr.size();
    int l = 1;
    int r = arr[m-1]-1;
    int flag = 1;
    for(int i=m-2; i>=0; i--){
        if(l > r){
            flag = 0;
            break;
        }
        l = arr[i] - l;
        r = arr[i] - r;
        if(l > r) swap(l, r);
        if(r < 1){
            flag = 0;
            break;
        }
        l = max(l, 1);
    }
    if(l > r){
        flag = 0;
    }
    if(!flag){
        cout << -1 << endl;
    } else{
        cout << r << endl;
    }
    return 0;
}