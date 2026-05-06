#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);
    int cnt = 1;
    int thres = arr[0].second;
    for(int i=1; i<n; i++){
        if(arr[i].first >= thres){
            cnt++;
            thres = arr[i].second;
        }
    }
    cout << cnt << endl;
    return 0;
}