#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

static bool comp(vector<int>& v1, vector<int>& v2){
    if(v1[0] != v2[0]) return v1[0] < v2[0];
    else return v1[1] > v2[1];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i=0; i<n; i++){
        int l, r;
        cin >> l >> r;
        arr[i].push_back(l);
        arr[i].push_back(r);
        arr[i].push_back(i);
    }
    sort(arr.begin(), arr.end(), comp);
    int i;
    for(i=1; i<n; i++){
        if(arr[i][1] <= arr[i-1][1]) break;
    }
    if(i == n){
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    int x = arr[i][2]+1;
    int y = arr[i-1][2]+1;
    cout << x << " " << y << endl;
    return 0;
}