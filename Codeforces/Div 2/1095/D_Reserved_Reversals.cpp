#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(vector<int>& arr, int l, int r){
    int n = arr.size();
    vector<int> preMax(n);
    vector<int> sufMin(n);
    preMax[0] = arr[0];
    for(int i=1; i<n; i++) preMax[i] = max(preMax[i-1], arr[i]);
    sufMin[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) sufMin[i] = min(sufMin[i+1], arr[i]);
    for(int i=0; i<n-1; i++){
        int x = preMax[i];
        int y = sufMin[i+1];
        if(x <= y) continue;
        if(l < y || r > x) continue;
        return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> oArr;
    vector<int> eArr;
    for(int i=0; i<n; i++){
        if(arr[i]&1) oArr.push_back(arr[i]);
        else eArr.push_back(arr[i]);
    }
    if(oArr.empty()){
        if(is_sorted(eArr.begin(), eArr.end())) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    if(eArr.empty()){
        if(is_sorted(oArr.begin(), oArr.end())) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    int l1 = INT_MAX, r1 = INT_MIN;
    int l2 = INT_MAX, r2 = INT_MIN;
    for(auto val : oArr){
        l1 = min(l1, val);
        r1 = max(r1, val);
    }
    for(auto val : eArr){
        l2 = min(l2, val);
        r2 = max(r2, val);
    }
    if(f(oArr, l2, r2) && f(eArr, l1, r1)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}