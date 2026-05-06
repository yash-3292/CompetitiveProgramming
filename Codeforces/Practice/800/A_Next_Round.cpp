#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i] >= arr[k-1] && arr[i] > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}