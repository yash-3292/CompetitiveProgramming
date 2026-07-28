#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        vector<int> temp(n);
        for(int i=0; i<n; i++) cin >> temp[i];
        reverse(temp.begin(), temp.end());
        int j = 0;
        while(j < n && temp[j] == 1) j++;
        arr.push_back(j);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(i == 0){
            arr[i] = 0;
        } else{
            arr[i] = min(arr[i], arr[i-1]+1);
        }
    }
    cout << arr[n-1]+1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}