#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = arr[n-1] - arr[0] + 1;
    vector<int> temp;
    for(int i=0; i<n-1; i++){
        temp.push_back(arr[i+1]-arr[i]-1);
    }
    sort(temp.begin(), temp.end(), greater<int>());
    for(int i=0; i<k-1; i++){
        ans -= temp[i];
    }
    cout << ans << endl;
    return 0;
}