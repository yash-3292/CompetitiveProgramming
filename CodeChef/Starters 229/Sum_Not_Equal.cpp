#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
            arr[i].second = i+1;
        }
        sort(arr.begin(), arr.end());
        if(arr[n-1].first == 0) cout << -1 << endl;
        else cout << arr[n-1].second << " " << arr[n-2].second << " " << arr[n-3].second << endl;
    }
    return 0;
}