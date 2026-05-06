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
            arr[i].second = (i%2);
        }
        sort(arr.begin(), arr.end());
        int flag = 1;
        for(int i=1; i<n; i++){
            if(arr[i].second == arr[i-1].second) flag = 0;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}