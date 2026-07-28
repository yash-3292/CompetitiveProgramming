#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for(int i=0; i<n; i++){
        int sz;
        cin >> sz;
        vector<int> temp(sz);
        for(int j=0; j<sz; j++) cin >> temp[j];
        arr.push_back(temp);
    }
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << arr[x][y] << endl;
    return 0;
}