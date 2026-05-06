#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
            arr[i].first %= k;
            if(arr[i].first != 0) arr[i].first = k - arr[i].first;
            arr[i].second = i+1;
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            cout << arr[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}
