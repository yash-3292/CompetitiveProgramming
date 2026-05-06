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
        arr.push_back({x, 0});
        arr.push_back({y, 1});
    }
    sort(arr.begin(), arr.end());
    int maxi = 0;
    int cnt = 0;
    vector<int> ans;
    for(int i=0; i<2*n; i++){
        cout << arr[i].first << " " << arr[i].second << " " << cnt << endl;
        if(arr[i].second == 0){
            cnt++;
            ans.push_back(cnt);
        } else{
            cnt--;
        }
        maxi = max(maxi, cnt);
    }
    cout << maxi << endl;
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}